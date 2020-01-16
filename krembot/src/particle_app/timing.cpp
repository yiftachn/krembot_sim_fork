//
// Created by eli on 1/16/20.
//

#include "timing.h"


#include <chrono>
#include <thread>

using namespace std::chrono;

void delay(int millis) {
    std::this_thread::sleep_for(milliseconds(millis));
}

long millis() {
    milliseconds ms = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );
    return ms.count();
}
