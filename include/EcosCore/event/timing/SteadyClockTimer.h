// File: ecoscore/event/timing/SteadyClockTimer.h
// EcosCore/event/util/timing/SteadyClockTimer.h
#ifndef ECOSCORE_ECOSCORE_EVENT_TIMING_STEADYCLOCKTIMER_H
#define ECOSCORE_ECOSCORE_EVENT_TIMING_STEADYCLOCKTIMER_H

#include "VirtualTimer.h"
#include <chrono>
#include <iostream>
#include <string_view>

namespace EcosCore::event::util::timing {

    /**
     * SteadyClockTimer:
     * Uses std::chrono::steady_clock to measure elapsed time.
     */
    class SteadyClockTimer : public VirtualTimer {
    public:
        void Start() override {
            start_ = std::chrono::steady_clock::now();
} // namespace EcosCore::event::util::timing

        void Stop() override {
            end_ = std::chrono::steady_clock::now();
        }

        double ElapsedMilliseconds() const override {
            return std::chrono::duration<double, std::milli>(end_ - start_).count();
        }

        void LogElapsed(std::string_view eventTypeName) const override {
            std::cout << "[Timer] Event " << eventTypeName << " took " << ElapsedMilliseconds() << " ms\n";
        }

    private:
        std::chrono::steady_clock::time_point start_;
        std::chrono::steady_clock::time_point end_;
    };

} // namespace EcosCore::event::util::timing

#endif // ECOSCORE_ECOSCORE_EVENT_TIMING_STEADYCLOCKTIMER_H
