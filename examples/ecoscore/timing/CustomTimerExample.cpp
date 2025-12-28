// examples/event/timing/CustomTimerExample.cpp

#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/util/TimingCallback.h"
#include "EcosCore/event/util/ITimer.h"
#include "EcosCore/event/Event.h"
#include <chrono>
#include <iostream>

class SimpleTimer : public EcosCore::event::util::ITimer {
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point end_time;
public:
    void Start() override {
        start_time = std::chrono::steady_clock::now();
    }
    void Stop() override {
        end_time = std::chrono::steady_clock::now();
    }
    double ElapsedMilliseconds() const override {
        return std::chrono::duration<double, std::milli>(end_time - start_time).count();
    }
    void LogElapsed(std::string_view eventTypeName) const override {
        std::cout << "[Timer] Event " << eventTypeName << " took " << ElapsedMilliseconds() << " ms\n";
    }
};

struct MyEvent : EcosCore::event::Event {};

int main() {
    EcosCore::event::core::EventDispatcher dispatcher;

    SimpleTimer timer;

    dispatcher.AddCallback<MyEvent>(
        EcosCore::event::util::TimingCallback<MyEvent>::instance(timer),
        EcosCore::tag::Before::instance(),
        EcosCore::tag::Medium::instance());

    MyEvent event;
    dispatcher.Dispatch(event, EcosCore::tag::Before::instance());

    return 0;
}
