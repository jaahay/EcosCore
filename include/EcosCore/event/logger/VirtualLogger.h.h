// EcosCore/event/util/logger/VirtualLogger.h
#ifndef ECOSCORE_EVENT_UTIL_LOGGER_VIRTUALLOGGER_H
#define ECOSCORE_EVENT_UTIL_LOGGER_VIRTUALLOGGER_H

#include <string_view>

namespace EcosCore::event::util::logger {

    /**
     * VirtualLogger: abstract logging interface.
     */
    class VirtualLogger {
    public:
        virtual ~VirtualLogger() = default;
        virtual void Log(std::string_view tag, std::string_view message) const = 0;
    };

} // namespace EcosCore::event::util::logger

#endif // ECOSCORE_EVENT_UTIL_LOGGER_VIRTUALLOGGER_H
