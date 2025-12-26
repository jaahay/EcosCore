// EcosCore/event/util/ILogger.h
#ifndef ECOSCORE_EVENT_UTIL_ILOGGER_H
#define ECOSCORE_EVENT_UTIL_ILOGGER_H

#include <string_view>

namespace ecoscore::event::util {

    // Abstract logger interface for consumers to implement
    struct ILogger {
        virtual ~ILogger() = default;

        // Log a message with event type info
        virtual void Log(std::string_view eventTypeName, std::string_view message) = 0;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_ILOGGER_H
