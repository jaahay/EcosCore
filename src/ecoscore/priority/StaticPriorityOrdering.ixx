// src/ecoscore/priority/StaticPriorityOrdering.ixx
module ecoscore.priority.StaticPriorityOrdering;

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
import ecoscore.type.StructType;

export namespace ecoscore::priority {

    template <typename Priority>
        requires std::derived_from<Priority, ecoscore::type::StructType>
    class StaticPriorityOrdering {
    public:
        void AddDependency(const Priority& higher, const Priority& lower) {
            adjacency_[&higher].insert(&lower);
            adjacency_[&lower];
            if (HasCycle()) {
                adjacency_[&higher].erase(&lower);
                throw std::runtime_error("StaticPriorityOrdering: cycle detected");
            }
        }

        bool IsHigher(const Priority* higher, const Priority* lower) const {
            std::set<const Priority*> visited;
            return Dfs(higher, lower, visited);
        }

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
            if (!adjacency_.count(current) || visited.count(current)) return false;
            visited.insert(current);
            for (const auto* next : adjacency_.at(current)) {
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

}
