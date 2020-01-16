//
// Created by eli on 1/16/20.
//

#include "particle_string.h"

String::String(const String & value) {
    ss.str(value.ss.str());
}

String::String(const char * str) {
    ss.str(str);
}

bool String::operator==(const char * other) {
    bool isEqual = (
            strncmp(ss.str().c_str(), other, ss.str().size()) == 0
    );
    return isEqual;
}

void String::operator=(const String & other) {
    ss.clear();
    ss.str(other.ss.str());
}

String String::operator+(const String & other) {
    ss << other.ss.str();
    return ss.str();
}

String String::operator+(const char * other) {
    ss << other;
    return ss.str();
}