// File: ecoscore/event/logger/DebugLogger.h
// EcosCore/event/util/logger/DebugLogger.h
#ifndef ECOSCORE_ECOSCORE_EVENT_LOGGER_DEBUGLOGGER_H
#define ECOSCORE_ECOSCORE_EVENT_LOGGER_DEBUGLOGGER_H

#include "VirtualLogger.h"
#include <iostream>
#include <string_view>

namespace EcosCore::event::util::logger {

    /**
     * DebugLogger: writes logs to std::clog.
     */
    class DebugLogger : public VirtualLogger {
    public:
        static DebugLogger& instance() {
            static DebugLogger inst;
            return inst;
} // namespace EcosCore::event::util::logger

        void Log(std::string_view tag, std::string_view message) const override {
            std::clog << "[" << tag << "] " << message << "\n";
        }

    private:
        DebugLogger() = default;
        DebugLogger(const DebugLogger&) = delete;
        DebugLogger& operator=(const DebugLogger&) = delete;
    };

} // namespace EcosCore::event::util::logger

#endif // ECOSCORE_ECOSCORE_EVENT_LOGGER_DEBUGLOGGER_H
