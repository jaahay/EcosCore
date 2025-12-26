// EcosCore/event/core/PhaseInvoker.h
#ifndef ECOSCORE_EVENT_PHASE_INVOKER_H
#define ECOSCORE_EVENT_PHASE_INVOKER_H

#include "EcosCore/event/core/CallbackManager.h"
#include "EcosCore/event/core/EventContext.h"
#include "EcosCore/event/core/CallbackPhaseState.h"
#include "EcosCore/state/PriorityState.h"

#include <vector>
#include <typeindex>
#include <iostream>

using namespace ecoscore::state;

namespace ecoscore::event::core {

    class PhaseInvoker {
    public:
        explicit PhaseInvoker(const CallbackManager& cbManager)
            : callbackManager_(cbManager) {
        }

        bool InvokePhase(const std::vector<std::type_index>& hierarchy,
            const Event& event,
            const CallbackPhaseState& phase,
            bool generalToSpecific,
            EventContext& ctx) const {
            if (generalToSpecific) {
                for (const auto& type : hierarchy) {
                    if (InvokeCallbacksForType(type, event, phase, ctx))
                        return true;
                    if (ctx.IsCanceled())
                        return true;
                    if (ctx.ShouldSkipPhase())
                        break;
                }
            }
            else {
                for (auto it = hierarchy.rbegin(); it != hierarchy.rend(); ++it) {
                    if (InvokeCallbacksForType(*it, event, phase, ctx))
                        return true;
                    if (ctx.IsCanceled())
                        return true;
                    if (ctx.ShouldSkipPhase())
                        break;
                }
            }
            return false;
        }

    private:
        bool InvokeCallbacksForType(std::type_index type,
            const Event& event,
            const CallbackPhaseState& phase,
            EventContext& ctx) const {
            auto callbacks = callbackManager_.GetCallbacks(type);
            for (const auto& [handle, cb] : callbacks) {
                // Narrow Phase and Priority states
                auto cbPhase = dynamic_cast<const CallbackPhaseState*>(cb->Phase());
                if (cbPhase && *cbPhase == phase) {
                    try {
                        const auto& result = cb->Invoke(event, ctx);
                        if (&result == &Stop::instance() || ctx.IsCanceled())
                            return true;
                        if (ctx.ShouldSkipPhase())
                            break;
                    }
                    catch (const std::exception& ex) {
                        std::cerr << "Exception in event callback: " << ex.what() << "\n";
                    }
                    catch (...) {
                        std::cerr << "Unknown exception in event callback\n";
                    }
                }
            }
            return false;
        }

        const CallbackManager& callbackManager_;
    };

} // namespace ecoscore::event::core

#endif // ECOSCORE_EVENT_PHASE_INVOKER_H
