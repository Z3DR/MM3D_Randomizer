#pragma once

#include <3ds.h>

#include "keys.hpp"

#include <vector>

enum class SearchMode {
    ReachabilitySearch,
    GeneratePlaythrough,
    CheckBeatable,
    AllLocationsReachable,
};

int VanillaFill();
int Fill();
int NoLogicFill();
void MultiLocationCheck(LocationKey key);

std::vector<LocationKey> GetAccessibleLocations(const std::vector<LocationKey>& allowedLocations,
                                                  SearchMode mode = SearchMode::ReachabilitySearch);
