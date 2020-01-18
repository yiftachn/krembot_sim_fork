//
// Created by eli on 1/18/20.
//

#include "cbumpers_result.h"

BumpersRes::BumpersRes() {
    m_bumpers.reserve(NUM_OF_BUMPERS);
    m_bumpers.push_back(&front);
    m_bumpers.push_back(&front_right);
    m_bumpers.push_back(&right);
    m_bumpers.push_back(&rear_right);
    m_bumpers.push_back(&rear);
    m_bumpers.push_back(&rear_left);
    m_bumpers.push_back(&left);
    m_bumpers.push_back(&front_left);
}

bool BumpersRes::isAnyPressed() const
{
    for (const auto & bumper : m_bumpers) {
        if (bumper->isPressed()) {
            return true;
        }
        return false;
    }
}