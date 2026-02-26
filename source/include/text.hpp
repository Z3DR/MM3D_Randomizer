#pragma once

#include <string>

#define PLURAL 0
#define SINGULAR 1

class Text {
public:
    Text() = default;
    Text(std::string generic)
      : NAenglish(generic),
        NAfrench(generic),
        NAspanish(generic) {}

    Text(std::string english_, std::string french_, std::string spanish_)
      : NAenglish(std::move(english_)),
        NAfrench(std::move(french_)),
        NAspanish(std::move(spanish_)) {}

    const std::string& GetEnglish() const {
        return NAenglish;
    }

    const std::string& GetFrench() const {
        if (NAfrench.length() > 0) {
            return NAfrench;
        }
        return NAenglish;
    }

    const std::string& GetSpanish() const {
        if (NAspanish.length() > 0) {
            return NAspanish;
        }
        return NAenglish;
    }

    Text operator+ (const Text& right) const {
        return Text{NAenglish + right.GetEnglish(), NAfrench + right.GetFrench(), NAspanish + right.GetSpanish()};
    }

    Text operator+ (const std::string& right) const {
        return Text{NAenglish + right, NAfrench + right, NAspanish + right};
    }

    bool operator==(const Text& right) const {
        return NAenglish == right.NAenglish;
    }

    bool operator!=(const Text& right) const {
        return !operator==(right);
    }

    void Replace(std::string oldStr, std::string newStr) {

        for (std::string* str : {&NAenglish, &NAfrench, &NAspanish}) {
            size_t position = str->find(oldStr);
            while (position != std::string::npos) {
              str->replace(position, oldStr.length(), newStr);
              position = str->find(oldStr);
            }
        }
    }

    //find the appropriate bars that separate singular from plural
    void SetForm(int form) {
        for (std::string* str : {&NAenglish, &NAfrench, &NAspanish}) {

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
};
