// File: ecoscore/callback/core/CallbackResultSet.h
// EcosCore/event/core/CallbackResultSet.h
#ifndef ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKRESULTSET_H
#define ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKRESULTSET_H

#include <set>
#include <typeindex>
#include <vector>
#include <string>
#include <iostream>

namespace EcosCore::event::core {

    /**
     * CallbackResultSet:
     * Holds a set of callback result tags, supports conflict detection and string representation.
     */
    class CallbackResultSet {
        std::set<std::type_index> tags_;

    public:
        template <typename Tag>
        void add() {
            tags_.insert(std::type_index(typeid(Tag)));
} // namespace EcosCore::event::core

        template <typename Tag>
        bool contains() const {
            return tags_.count(std::type_index(typeid(Tag))) > 0;
        }

        bool isValid() const {
            // Example conflict: cannot have both Stop and Continue
            if (contains<EcosCore::tag::Stop>() && contains<EcosCore::tag::Continue>()) {
                return false;
            }
            // Add other conflict detection as needed
            return true;
        }

        std::vector<std::string> names() const {
            std::vector<std::string> result;
            for (const auto& t : tags_) {
                result.push_back(t.name());
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream& os, const CallbackResultSet& set) {
            os << "CallbackResultSet{";
            bool first = true;
            for (const auto& t : set.tags_) {
                if (!first) os << ", ";
                os << t.name();
                first = false;
            }
            os << "}";
            return os;
        }
    };

} // namespace EcosCore::event::core

#endif // ECOSCORE_ECOSCORE_CALLBACK_CORE_CALLBACKRESULTSET_H
