//
// Created by eli on 1/16/20.
//

#ifndef KREMBOT_PARTICLE_STRING_H
#define KREMBOT_PARTICLE_STRING_H

#include <string>
#include <sstream>
#include <cstring>

class String {
private:
    std::ostringstream ss;

public:
    String() = default;

    template <class T>
    String(const T & value) {
        ss << value;
    }

    String(const String & value);

    String(const char * str);

    bool operator==(const char * other);

    void operator=(const String & other);

    String operator+(const String & other);

    String operator+(const char * other);
};


#endif //KREMBOT_PARTICLE_STRING_H
