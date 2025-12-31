// EcosCore/event/core/CallbackHandle.h
#ifndef ECOSCORE_EVENT_CORE_CALLBACK_HANDLE_H
#define ECOSCORE_EVENT_CORE_CALLBACK_HANDLE_H

#include <cstdint>
#include <atomic>
#include <ostream>

namespace EcosCore::event {

    /**
     * CallbackHandle: Strong typedef wrapping a unique integral callback ID.
     */
    class CallbackHandle {
    public:
        constexpr CallbackHandle() noexcept : id_(0) {}
        explicit constexpr CallbackHandle(uint64_t id) noexcept : id_(id) {}

        bool operator==(const CallbackHandle& other) const noexcept { return id_ == other.id_; }
        bool operator!=(const CallbackHandle& other) const noexcept { return id_ != other.id_; }
        bool operator<(const CallbackHandle& other) const noexcept { return id_ < other.id_; }
        explicit operator bool() const noexcept { return id_ != 0; }

        uint64_t value() const noexcept { return id_; }

    private:
        uint64_t id_;
    };

    inline std::ostream& operator<<(std::ostream& os, const CallbackHandle& handle) {
        os << "CallbackHandle(" << handle.value() << ")";
        return os;
    }

    /**
     * CallbackHandleGenerator: Generates unique callback handles.
     */
    class CallbackHandleGenerator {
    public:
        static CallbackHandle Generate() {
            static std::atomic<uint64_t> counter{ 1 };
            return CallbackHandle{ counter.fetch_add(1, std::memory_order_relaxed) };
        }
    };

} // namespace EcosCore::event

#endif // ECOSCORE_EVENT_CORE_CALLBACK_HANDLE_H
