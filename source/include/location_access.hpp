#pragma once

#include <string>
#include <vector>
#include <list>

#include "logic.hpp"
#include "hint_list.hpp"
#include "keys.hpp"

typedef bool (*ConditionFn)();

class EventAccess {
public:

    explicit EventAccess(bool* event_, std::vector<ConditionFn> conditions_met_)
        : event(event_) {
        conditions_met.resize(2);
        for (size_t i = 0; i < conditions_met_.size(); i++) {
            conditions_met[i] = conditions_met_[i];
        }
    }

    bool ConditionsMet() const {
        if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_NONE) || Settings::Logic.Is(rnd::LogicSetting::LOGIC_VANILLA)) {
            return true;
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHLESS)) {
            return conditions_met[0]();
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHED)) {
            if (conditions_met[0]()) {
                return true;
            } else if (conditions_met[1] != NULL) {
                return conditions_met[1]();
            }
        }
        return false;
    }

    void EventOccurred() {
        *event = true;
    }

    bool GetEvent() const {
        return *event;
    }

private:
    bool* event;
    std::vector<ConditionFn> conditions_met;
};

//this class is meant to hold an item location with a boolean function to determine its accessibility from a specific area
class LocationAccess {
public:

    explicit LocationAccess(LocationKey location_, std::vector<ConditionFn> conditions_met_)
        : location(location_) {
        conditions_met.resize(2);
        for (size_t i = 0; i < conditions_met_.size(); i++) {
            conditions_met[i] = conditions_met_[i];
        }
    }

    bool GetConditionsMet() const {
        if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_NONE) || Settings::Logic.Is(rnd::LogicSetting::LOGIC_VANILLA)) {
            return true;
        } else if (Settings::Logic.Is(rnd::LogicSetting::LOGIC_GLITCHLESS)) {
            return conditions_met[0]();
        } else if (Settings::Logic.Is(LogicSetting::LOGIC_GLITCHED)) {
            if (conditions_met[0]()) {
                return true;
            } else if (conditions_met[1] != NULL) {
                return conditions_met[1]();
            }
        }
        return false;
    }

    bool ConditionsMet() const;

    //Makes sure shop locations are buyable with the current wallet (and bottle/bomb bag for refills)
    bool CanBuy() const;

    LocationKey GetLocation() const {
        return location;
    }

private:
    LocationKey location;
    std::vector<ConditionFn> conditions_met;
};

class Entrance;
enum class EntranceType;

class Area {
public:
    Area();
    Area(std::string regionName_, std::string scene_, HintKey hintKey_,
         std::vector<EventAccess> events_,
         std::vector<LocationAccess> locations_,
         std::list<Entrance> exits_);
    ~Area();

    std::string regionName;
    std::string scene;
    HintKey     hintKey;
    std::vector<EventAccess> events;
    std::vector<LocationAccess> locations;
    std::list<Entrance> exits;
    //^ The above exits are now stored in a list instead of a vector because
    //the entrance randomization algorithm plays around with pointers to these
    //entrances a lot. By putting the entrances in a list, we don't have to
    //worry about a vector potentially reallocating itself and invalidating all our
    //entrance pointers.
    bool addedToPool = false;

    bool UpdateEvents();

    void AddExit(AreaKey parentKey, AreaKey newExitKey, ConditionFn condition);

    void RemoveExit(Entrance* exitToRemove);

    void DisconnectExit(AreaKey exitToDisconnect);

    void SetAsPrimary(AreaKey exitToBePrimary);

    Entrance* GetExit(AreaKey exit);


    bool HasAccess() const {
      return true;
    }

    bool AllAccess() const {
      return true;
    }

    //Check to see if an exit can be access as both ages at both times of day
    bool CheckAllAccess(AreaKey exitKey);

    const HintText& GetHint() const {
      return Hint(hintKey);
    }
    
    bool HereCheck(ConditionFn condition) {
        //update helpers and check condition
        Logic::UpdateHelpers();
        bool hereVal = condition();

        return hereVal;
    }

    bool CanPlantBeanCheck() const;
    bool AllAccountedFor() const;

    void ResetVariables();


};

    /*extern std::array<Area, KEY_ENUM_MAX> areaTable;
    extern std::vector<EventAccess> grottoEvents;
    bool Here(const AreaKey area, ConditionFn condition);
    bool HasAccessTo(const AreaKey area);*/

namespace Areas {

  extern void AccessReset();
  extern void ResetAllLocations();
} //namespace Exits

void  AreaTable_Init();
Area* AreaTable(const AreaKey areaKey);
std::vector<Entrance*> GetShuffleableEntrances(EntranceType type, bool onlyPrimary = true);
