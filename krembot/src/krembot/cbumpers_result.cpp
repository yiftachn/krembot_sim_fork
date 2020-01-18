//
// Created by eli on 1/18/20.
//

#include "cbumpers_result.h"

BumpersRes::BumpersRes() {
    m_bumpers.reserve(NUM_OF_BUMPERS);
    m_bumpers.emplace_back(front, "|   FRONT   |", 0);
    m_bumpers.emplace_back(front_right, "|FRONT RIGHT|", 1);
    m_bumpers.emplace_back(right, "|   RIGHT   |", 2);
    m_bumpers.emplace_back(rear_right, "|REAR  RIGHT|", 3);
    m_bumpers.emplace_back(rear, "|   REAR    |", 4);
    m_bumpers.emplace_back(rear_left, "| REAR LEFT |", 5);
    m_bumpers.emplace_back(left, "|   LEFT    |", 6);
    m_bumpers.emplace_back(front_left, "|FRONT LEFT |", 7);
}

bool BumpersRes::isAnyPressed() const
{
    for (const auto & bumper : m_bumpers) {
        if (bumper.isPressed()) {
            return true;
        }
        return false;
    }
}