#pragma once
#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define UTILITY_API
#endif

namespace Utility {
    namespace Time {
        namespace Timer {

            class UTILITY_API Timer {
            private:
                bool clear = false;

            public:
                template<typename Function>
                void setTimeout(Function function, int delay);

                void setInterval(int interval);

                void stop();

            };
        }
    }
}