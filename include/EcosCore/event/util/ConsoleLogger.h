// EcosCore/event/util/ConsoleLogger.h
#ifndef ECOSCORE_EVENT_UTIL_CONSOLE_LOGGER_H
#define ECOSCORE_EVENT_UTIL_CONSOLE_LOGGER_H

#include "ILogger.h"
#include <iostream>
#include <mutex>

namespace ecoscore::event::util {

    class ConsoleLogger : public ILogger {
    public:
        static ConsoleLogger& instance() {
            static ConsoleLogger inst;
            return inst;
        }

        void Log(std::string_view eventTypeName, std::string_view message) override {
            std::lock_guard lock(mutex_); // thread-safe console output
            std::cout << "[LOG][" << eventTypeName << "] " << message << "\n";
        }

    private:
        ConsoleLogger() = default;
        std::mutex mutex_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_CONSOLE_LOGGER_H
