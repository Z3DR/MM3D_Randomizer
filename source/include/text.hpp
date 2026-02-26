#pragma once

#include <string>

#define PLURAL 0
#define SINGULAR 1

class Text {
public:
    Text() = default;
    Text(std::string generic)
      : NAenglish(generic), NAfrench(generic), NAspanish(generic),
        //EURgerman(generic),   //EURItalian(generic),   //Japanese? Either way, MM3D doesn't support Dutch
        EURenglish(generic), EURfrench(generic), EURspanish(generic) {}

    Text(std::string english_, std::string french_, std::string spanish_)
      : NAenglish(std::move(english_)),  NAfrench(std::move(french_)),  NAspanish(std::move(spanish_)),
        //EURgerman(std::move(german_)),   //EURitalian(std::move(italian_)),
        EURenglish(std::move(english_)), EURfrench(std::move(french_)), EURspanish(std::move(spanish_)) {}

    Text(std::string NAenglish_, std::string NAfrench_, std::string NAspanish_,
         std::string EURenglish_, std::string EURfrench_, std::string EURspanish_)
      : NAenglish(std::move(NAenglish_)),   NAfrench(std::move(NAfrench_)),   NAspanish(std::move(NAspanish_)),
        //EURgerman(std::move(EURgerman_)),   //EURitalian(std::move(EURitalian_)),
        EURenglish(std::move(EURenglish_)), EURfrench(std::move(EURfrench_)), EURspanish(std::move(EURspanish_)) {
            //Fallback to NA string if EUR one is blank
            //Should allow for easier selective definition
            if (EURenglish.length() == 0) {EURenglish = NAenglish;}
            if (EURfrench.length() == 0) {EURfrench = NAfrench;}
            if (EURspanish.length() == 0) {EURspanish = NAspanish;}
        }

    const std::string& GetNAEnglish() const {
        return NAenglish;
    }

    const std::string& GetNAFrench() const {
        if (NAfrench.length() > 0) {
            return NAfrench;
        }
        return NAenglish;
    }

    const std::string& GetNASpanish() const {
        if (NAspanish.length() > 0) {
            return NAspanish;
        }
        return NAenglish;
    }

    // const std::string& GetEURGerman() const {
    //     if (EURgerman.length() > 0) {
    //         return EURgerman;
    //     }
    //     return EURenglish;
    // }

    // const std::string& GetEURItalian() const {
    //     if (EURitalian.length() > 0) {
    //         return EURitalian;
    //     }
    //     return EURenglish;
    // }

    const std::string& GetEUREnglish() const {
        return EURenglish;
    }

    const std::string& GetEURFrench() const {
        if (EURfrench.length() > 0) {
            return EURfrench;
        }
        return EURenglish;
    }

    const std::string& GetEURSpanish() const {
        if (EURspanish.length() > 0) {
            return EURspanish;
        }
        return EURenglish;
    }

    Text operator+ (const Text& right) const {
        return Text{
            NAenglish + right.GetNAEnglish(), NAfrench + right.GetNAFrench(), NAspanish + right.GetNASpanish(),
            //EURgerman + right.GetEURGerman(), //EURitalian + right.GetEURItalian(),
            EURenglish + right.GetEUREnglish(), EURfrench + right.GetEURFrench(), EURspanish + right.GetEURSpanish()
        };
    }

    Text operator+ (const std::string& right) const {
        return Text{
            NAenglish + right, NAfrench + right, NAspanish + right,
            //EURgerman + right, //EURitalian + right,
            EURenglish + right, EURfrench + right, EURspanish + right
        };
    }

    bool operator==(const Text& right) const {
        return NAenglish == right.NAenglish;
    }

    bool operator!=(const Text& right) const {
        return !operator==(right);
    }

    void Replace(std::string oldStr, std::string newStr) {

        for (std::string* str : {&NAenglish, &NAfrench, &NAspanish, /*&EURgerman, &EURitalian,*/ &EURenglish, &EURfrench, &EURspanish}) {
            size_t position = str->find(oldStr);
            while (position != std::string::npos) {
              str->replace(position, oldStr.length(), newStr);
              position = str->find(oldStr);
            }
        }
    }

    //find the appropriate bars that separate singular from plural
    void SetForm(int form) {
        for (std::string* str : {&NAenglish, &NAfrench, &NAspanish, /*&EURgerman, &EURitalian,*/ &EURenglish, &EURfrench, &EURspanish}) {

            size_t firstBar = str->find('|');
            if (firstBar != std::string::npos) {

                size_t secondBar = str->find('|', firstBar + 1);
                if (secondBar != std::string::npos) {

                    size_t thirdBar = str->find('|', secondBar + 1);
                    if (thirdBar != std::string::npos) {

                        if (form == SINGULAR) {
                            str->erase(secondBar, thirdBar - secondBar);
                        } else {
                            str->erase(firstBar, secondBar - firstBar);
                        }
                    }
                }
            }
        }
        //remove the remaining bar
        this->Replace("|", "");
    }

    std::string NAenglish = "";
    std::string NAfrench = "";
    std::string NAspanish = "";
    //std::string EURgerman = "";
    //std::string EURitalian  = "";
    std::string EURenglish = "";
    std::string EURfrench  = "";
    std::string EURspanish = "";
};
