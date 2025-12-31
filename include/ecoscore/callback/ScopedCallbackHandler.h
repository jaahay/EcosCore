// EcosCore/event/ScopedCallbackHandler.h
#ifndef ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H
#define ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H

#include <atomic>
#include <utility>
#include "EcosCore/event/core/EventDispatcher.h"
#include "EcosCore/event/core/CallbackHandle.h"
#include "EcosCore/event/core/NullEventDispatcher.h"

namespace EcosCore::event {

    /**
     * ScopedCallbackHandler manages callback lifetime by unregistering on destruction.
     */
    class ScopedCallbackHandler {
    public:
        ScopedCallbackHandler() noexcept
            : dispatcher_(core::NullEventDispatcher::instance()), handle_() {
        }

        ScopedCallbackHandler(core::EventDispatcher& dispatcher, core::CallbackHandle handle) noexcept
            : dispatcher_(dispatcher), handle_(handle) {
        }

        ~ScopedCallbackHandler() {
            auto h = handle_.exchange(core::CallbackHandle{});
            if (h) {
                dispatcher_.RemoveCallback(h);
            }
        }

        ScopedCallbackHandler(const ScopedCallbackHandler&) = delete;
        ScopedCallbackHandler& operator=(const ScopedCallbackHandler&) = delete;

        ScopedCallbackHandler(ScopedCallbackHandler&& other) noexcept
            : dispatcher_(other.dispatcher_), handle_(other.handle_.exchange(core::CallbackHandle{})) {
            other.dispatcher_ = core::NullEventDispatcher::instance();
        }

        ScopedCallbackHandler& operator=(ScopedCallbackHandler&& other) noexcept {
            if (this != &other) {
                auto h = handle_.exchange(core::CallbackHandle{});
                if (h) {
                    dispatcher_.RemoveCallback(h);
                }
                dispatcher_ = other.dispatcher_;
                handle_ = other.handle_.exchange(core::CallbackHandle{});
                other.dispatcher_ = core::NullEventDispatcher::instance();
            }
            return *this;
        }

        explicit operator bool() const noexcept {
            return static_cast<bool>(handle_);
        }

        core::CallbackHandle Get() const noexcept {
            return handle_.load();
        }

    private:
        core::EventDispatcher& dispatcher_;
        std::atomic<core::CallbackHandle> handle_;
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H
