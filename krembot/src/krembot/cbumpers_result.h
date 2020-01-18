//
// Created by eli on 1/18/20.
//

#ifndef KREMBOT_CBUMPERS_RESULT_H
#define KREMBOT_CBUMPERS_RESULT_H


#include <string>
#include <vector>

enum BumperState
{
    UNDEFINED,
    PRESSED,
    UNPRESSED
};

struct BumpersRes
{
private:
    struct data {
        BumperState & bumper;
        std::string name {};
        uint8_t index = 0;
        data(BumperState & bumper, const std::string & bumperName, uint8_t ringIndex) :
                bumper{bumper},
                name{bumperName},
                index{ringIndex} {}

        inline bool isPressed() const { return (bumper == BumperState::PRESSED); }
    };

    static const uint8_t NUM_OF_BUMPERS = 8;

    std::vector<data> m_bumpers;

    friend class CBumpers;

public:

    BumperState front = BumperState::UNPRESSED;
    BumperState front_right = BumperState::UNPRESSED;
    BumperState right = BumperState::UNPRESSED;
    BumperState rear_right = BumperState::UNPRESSED;
    BumperState rear = BumperState::UNPRESSED;
    BumperState rear_left = BumperState::UNPRESSED;
    BumperState left = BumperState::UNPRESSED;
    BumperState front_left = BumperState::UNPRESSED;

    BumpersRes();

    bool isAnyPressed() const ;
};


#endif //KREMBOT_CBUMPERS_RESULT_H
