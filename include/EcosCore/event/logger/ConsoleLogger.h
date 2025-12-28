// EcosCore/event/util/ConsoleLogger.h
#ifndef ECOSCORE_EVENT_UTIL_CONSOLELOGGER_H
#define ECOSCORE_EVENT_UTIL_CONSOLELOGGER_H

#include <iostream>
#include <string_view>

namespace EcosCore::event::util {

    /**
     * Logger that writes to std::cout.
     */
    class ConsoleLogger {
    public:
        static ConsoleLogger& instance() {
            static ConsoleLogger inst;
            return inst;
        }

        void Log(std::string_view tag, std::string_view message) const {
            std::cout << "[" << tag << "] " << message << "\n";
        }

    private:
        ConsoleLogger() = default;
        ConsoleLogger(const ConsoleLogger&) = delete;
        ConsoleLogger& operator=(const ConsoleLogger&) = delete;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_UTIL_CONSOLELOGGER_H
