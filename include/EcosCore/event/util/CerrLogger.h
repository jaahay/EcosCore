// EcosCore/event/util/CerrLogger.h
#ifndef ECOSCORE_EVENT_UTIL_CERR_LOGGER_H
#define ECOSCORE_EVENT_UTIL_CERR_LOGGER_H

#include "ILogger.h"
#include <iostream>
#include <mutex>

namespace ecoscore::event::util {

    class CerrLogger : public ILogger {
    public:
        static CerrLogger& instance() {
            static CerrLogger inst;
            return inst;
        }

        void Log(std::string_view eventTypeName, std::string_view message) override {
            std::lock_guard lock(mutex_); // thread-safe output
            std::cerr << "[ERR][" << eventTypeName << "] " << message << "\n";
        }

    private:
        CerrLogger() = default;
        std::mutex mutex_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_CERR_LOGGER_H
