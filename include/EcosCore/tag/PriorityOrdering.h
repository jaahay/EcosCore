// EcosCore/tag/PriorityOrdering.h
#ifndef ECOSCORE_TAG_PRIORITY_ORDERING_H
#define ECOSCORE_TAG_PRIORITY_ORDERING_H

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "EcosCore/type/StructType.h"

namespace EcosCore::tag {

    /**
     * PriorityOrdering manages relative ordering between priority tags (no fixed numeric levels).
     * Template parameter Priority must derive from StructType.
     */
    template <typename Priority>
        requires std::derived_from<Priority, EcosCore::type::StructType>
    class PriorityOrdering {
    public:
        /**
         * Add a "higher > lower" relation.
         */
        void AddDependency(const Priority& higher, const Priority& lower) {
            adjacency_[&higher].insert(&lower);
            // Ensure lower node exists
            adjacency_[&lower];

            if (HasCycle()) {
                adjacency_[&higher].erase(&lower);
                throw std::runtime_error("PriorityOrdering: cycle detected");
            }
        }

        /**
         * Returns true if higher > lower (transitive closure).
         */
        bool IsHigher(const Priority* higher, const Priority* lower) const {
            std::set<const Priority*> visited;
            return Dfs(higher, lower, visited);
        }

        /**
         * Returns a topological sorted vector of priority tags from highest to lowest.
         */
        std::vector<const Priority*> TopologicalSort() const {
            std::set<const Priority*> visited;
            std::vector<const Priority*> result;
            for (const auto& [node, _] : adjacency_) {
                if (visited.count(node) == 0) {
                    TopoDfs(node, visited, result);
                }
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

    private:
        std::map<const Priority*, std::set<const Priority*>> adjacency_;

        bool Dfs(const Priority* current, const Priority* target, std::set<const Priority*>& visited) const {
            if (current == target) return true;
            if (visited.count(current)) return false;
            visited.insert(current);
            auto it = adjacency_.find(current);
            if (it == adjacency_.end()) return false;
            for (const auto* next : it->second) {
                if (Dfs(next, target, visited)) return true;
            }
            return false;
        }

        bool HasCycleUtil(const Priority* node, std::set<const Priority*>& visited, std::set<const Priority*>& recursion_stack) const {
            visited.insert(node);
            recursion_stack.insert(node);

            for (const auto* neighbor : adjacency_.at(node)) {
                if (visited.count(neighbor) == 0) {
                    if (HasCycleUtil(neighbor, visited, recursion_stack)) return true;
                }
                else if (recursion_stack.count(neighbor) != 0) {
                    return true;
                }
            }
            recursion_stack.erase(node);
            return false;
        }

        bool HasCycle() const {
            std::set<const Priority*> visited;
            std::set<const Priority*> recursion_stack;

            for (const auto& [node, _] : adjacency_) {
                if (visited.count(node) == 0) {
                    if (HasCycleUtil(node, visited, recursion_stack)) return true;
                }
            }
            return false;
        }

        void TopoDfs(const Priority* node, std::set<const Priority*>& visited, std::vector<const Priority*>& result) const {
            visited.insert(node);
            for (const auto* next : adjacency_.at(node)) {
                if (visited.count(next) == 0) {
                    TopoDfs(next, visited, result);
                }
            }
            result.push_back(node);
        }
    };

} // namespace EcosCore::tag

#endif // ECOSCORE_TAG_PRIORITY_ORDERING_H
