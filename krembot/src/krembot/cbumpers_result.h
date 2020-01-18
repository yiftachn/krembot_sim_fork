//
// Created by eli on 1/18/20.
//

#ifndef KREMBOT_CBUMPERS_RESULT_H
#define KREMBOT_CBUMPERS_RESULT_H


#include <string>
#include <vector>

class BumperState
{
private:
    uint8_t m_state = UNDEFINED;
    std::string m_name {};
    uint8_t m_index = 0;

public:

    static const uint8_t UNDEFINED = 0;
    static const uint8_t PRESSED = 1;
    static const uint8_t UNPRESSED = 2;

    BumperState() = default;

    BumperState(const std::string & bumperName, uint8_t ringIndex) :
            m_name{bumperName},
            m_index{ringIndex} { }

    BumperState(const uint8_t state) : m_state {state} { }

    bool operator==(const BumperState & other) {
        return (this->m_state == other.m_state);
    }

    void operator=(const uint8_t state) {
        this->m_state = state;
    }

    inline const std::string & getName() const {
        return m_name;
    }

    inline uint8_t getIndex() const {
        return m_index;
    }

    inline bool isPressed() const {
        return (m_state == PRESSED);
    }
};

struct BumpersRes
{
private:

    std::vector<BumperState *> m_bumpers;

    friend class CBumpers;

public:

    static const uint8_t NUM_OF_BUMPERS = 8;

    /*
     * The following members are left here despite the fact
     * we have vector representing them, to support real
     * krembot API
     */
    BumperState front { "|   FRONT   |", 0};
    BumperState front_right { "|FRONT RIGHT|", 1};
    BumperState right { "|   RIGHT   |", 2};
    BumperState rear_right { "|REAR  RIGHT|", 3};
    BumperState rear { "|   REAR    |", 4};
    BumperState rear_left { "| REAR LEFT |", 5};
    BumperState left { "|   LEFT    |", 6};
    BumperState front_left { "|FRONT LEFT |", 7};

    BumpersRes();

    bool isAnyPressed() const ;
};


#endif //KREMBOT_CBUMPERS_RESULT_H
