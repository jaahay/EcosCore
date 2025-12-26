// EcosCore/event/ScopedCallbackHandler.h
#ifndef ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H
#define ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H

#include <atomic>
#include <utility>
#include "EcosCore/event/EventDispatcher.h"
#include "EcosCore/event/NullEventDispatcher.h"

namespace ecoscore::event {

    class ScopedCallbackHandler {
    public:
        // Default constructor uses NullEventDispatcher and zero handle
        ScopedCallbackHandler() noexcept
            : dispatcher_(null::NullEventDispatcher::instance()), handle_(0) {
        }

        // Construct with dispatcher and handle
        ScopedCallbackHandler(EventDispatcher& dispatcher, CallbackHandle handle) noexcept
            : dispatcher_(dispatcher), handle_(handle) {
        }

        ~ScopedCallbackHandler() {
            auto h = handle_.exchange(0);
            if (h != 0) {
                dispatcher_.RemoveCallback(h);
            }
        }

        // Disable copy semantics
        ScopedCallbackHandler(const ScopedCallbackHandler&) = delete;
        ScopedCallbackHandler& operator=(const ScopedCallbackHandler&) = delete;

        // Move constructor
        ScopedCallbackHandler(ScopedCallbackHandler&& other) noexcept
            : dispatcher_(other.dispatcher_), handle_(other.handle_.exchange(0)) {
            other.dispatcher_ = null::NullEventDispatcher::instance();
        }

        // Move assignment
        ScopedCallbackHandler& operator=(ScopedCallbackHandler&& other) noexcept {
            if (this != &other) {
                auto h = handle_.exchange(0);
                if (h != 0) {
                    dispatcher_.RemoveCallback(h);
                }
                dispatcher_ = other.dispatcher_;
                handle_ = other.handle_.exchange(0);
                other.dispatcher_ = null::NullEventDispatcher::instance();
            }
            return *this;
        }

        explicit operator bool() const noexcept {
            return handle_.load() != 0;
        }

        CallbackHandle Get() const noexcept {
            return handle_.load();
        }

    private:
        EventDispatcher& dispatcher_;
        std::atomic<CallbackHandle> handle_;
    };

} // namespace ecoscore::event

#endif // ECOSCORE_EVENT_SCOPED_CALLBACK_HANDLER_H
