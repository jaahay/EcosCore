// File: ecoscore/event/logger/CerrLogger.h
// EcosCore/event/util/CerrLogger.h
#ifndef ECOSCORE_EVENT_LOGGER_CERRLOGGER_H
#define ECOSCORE_EVENT_LOGGER_CERRLOGGER_H

#include <iostream>
#include <string_view>

namespace EcosCore::event::util {

    /**
     * Simple logger that writes to std::cerr.
     */
    class CerrLogger {
    public:
        static CerrLogger& instance() {
            static CerrLogger inst;
            return inst;
} // namespace EcosCore::event::util

        void Log(std::string_view tag, std::string_view message) const {
            std::cerr << "[" << tag << "] " << message << "\n";
        }

    private:
        CerrLogger() = default;
        CerrLogger(const CerrLogger&) = delete;
        CerrLogger& operator=(const CerrLogger&) = delete;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_LOGGER_CERRLOGGER_H
