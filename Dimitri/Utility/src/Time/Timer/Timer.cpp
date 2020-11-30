#include "Timer.h"
using namespace Utility;
template<typename Function>
inline void Time::Timer::Timer::setTimeout(Function function, int delay) {
    this->clear = false;
    std::thread t([=]() {
        if (this->clear) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if (this->clear) return;
        function();
        });
    t.detach();
}

inline void Time::Timer::Timer::setInterval(int interval) {
    this->clear = false;
    std::thread t([=]() {
        while (true) {
            if (this->clear) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            if (this->clear) return;
        }
    });
    t.detach();
}

void Time::Timer::Timer::stop() {
    this->clear = true;
}