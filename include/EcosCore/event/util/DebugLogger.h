// EcosCore/event/util/DebugLogger.h
#ifndef ECOSCORE_EVENT_UTIL_DEBUG_LOGGER_H
#define ECOSCORE_EVENT_UTIL_DEBUG_LOGGER_H

#include "ILogger.h"
#include <iostream>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>
#include <string_view>

namespace ecoscore::event::util {

    class DebugLogger : public ILogger {
    public:
        static DebugLogger& instance() {
            static DebugLogger inst;
            return inst;
        }

        void Log(std::string_view eventTypeName, std::string_view message) override {
            std::lock_guard lock(mutex_);

            auto now = std::chrono::system_clock::now();
            auto itt = std::chrono::system_clock::to_time_t(now);
            auto tm = *std::localtime(&itt);

            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S")
                << '.' << std::setfill('0') << std::setw(3) << ms.count()
                << " [Thread " << std::this_thread::get_id() << "] "
                << "[DEBUG][" << eventTypeName << "] " << message << '\n';

            std::cerr << oss.str();
        }

    private:
        DebugLogger() = default;
        std::mutex mutex_;
    };

} // namespace ecoscore::event::util

#endif // ECOSCORE_EVENT_UTIL_DEBUG_LOGGER_H
