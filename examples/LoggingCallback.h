// EcosCore/event/util/LoggingCallback.h
#ifndef ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H
#define ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H

#include "EcosCore/event/core/EventCallback.h"
#include "EcosCore/event/core/CallbackPhase.h"
#include "EcosCore/event/core/CallbackResultState.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/tag/Tag.h"
#include "EcosCore/state/TemplateType.h"
#include "EcosCore/event/util/ILogger.h"
#include "EcosCore/event/util/DebugLogger.h"

#include <typeinfo>
#include <variant>
#include <future>

namespace EcosCore::event::util {

    /**
     * LoggingCallback: logs event receipt using injected logger.
     */
    template <typename EventT>
    class LoggingCallback : public EcosCore::state::TemplateType<LoggingCallback<EventT>, EcosCore::state::StructType>,
        public EcosCore::event::core::IEventCallback {
    public:
        explicit LoggingCallback(const ILogger& logger = DebugLogger::instance())
            : logger_(logger) {
        }

        static const LoggingCallback& instance() {
            static LoggingCallback inst(DebugLogger::instance());
            return inst;
        }

        const EcosCore::tag::Phase& Phase() const override {
            return EcosCore::tag::Before::instance();
        }

        const EcosCore::tag::Priority& Priority() const override {
            return EcosCore::tag::Medium::instance();
        }

        std::variant<const EcosCore::tag::Result&, std::future<const EcosCore::tag::Result&>>
            Invoke(const EcosCore::event::Event& event, EcosCore::event::core::EventContext& ctx) const override {
            if (auto derived = dynamic_cast<const EventT*>(&event)) {
                logger_.Log(typeid(*derived).name(), "Event received");
            }
            return EcosCore::tag::Continue::instance();
        }

    private:
        const ILogger& logger_;
    };

} // namespace EcosCore::event::util

#endif // ECOSCORE_EVENT_UTIL_LOGGING_CALLBACK_H
