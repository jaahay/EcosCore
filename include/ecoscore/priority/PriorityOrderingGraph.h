// include/ecoscore/priority/PriorityOrderingGraph.h
#ifndef ECOSCORE_PRIORITY_PRIORITY_ORDERING_GRAPH_H
#define ECOSCORE_PRIORITY_PRIORITY_ORDERING_GRAPH_H

#include <map>
#include <set>
#include <vector>
#include <stack>
#include <typeindex>
#include <stdexcept>
#include <iostream>
#include "ecoscore/type/StructType.h"

namespace ecoscore::priority {

    /**
     * @brief Manages a DAG of priority nodes.
     *
     * Nodes are pointers to ecoscore::type::StructType singletons.
     */
    class PriorityOrderingGraph {
    public:
        using Node = const ecoscore::type::StructType*;

        /**
         * @brief Adds a dependency edge: higher > lower.
         * Throws if cycle detected or null node passed.
         */
        void AddDependency(Node higher, Node lower) {
            if (higher == nullptr || lower == nullptr) {
                throw std::invalid_argument("PriorityOrderingGraph: null node");
            }
            adjacency_[higher].insert(lower);
            adjacency_[lower]; // ensure node exists

            if (HasCycle()) {
                adjacency_[higher].erase(lower);
                throw std::runtime_error("PriorityOrderingGraph: cycle detected");
            }
        }

        /**
         * @brief Returns true if higher > lower (transitive closure).
         */
        bool IsHigher(Node higher, Node lower) const {
            std::set<Node> visited;
            return Dfs(higher, lower, visited);
        }

        /**
         * @brief Returns a topological sort of priority nodes from highest to lowest.
         */
        std::vector<Node> TopologicalSort() const {
            std::set<Node> visited;
            std::vector<Node> result;
            for (const auto& [node, _] : adjacency_) {
                if (visited.count(node) == 0) {
                    TopoDfs(node, visited, result);
                }
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

        /**
         * @brief Prints the graph contents to the output stream.
         */
        void Print(std::ostream& os) const {
            os << "PriorityOrderingGraph:\n";
            for (const auto& [node, edges] : adjacency_) {
                os << "  " << *node << " > { ";
                for (auto e : edges) {
                    os << *e << " ";
                }
                os << "}\n";
            }
        }

    private:
        std::map<Node, std::set<Node>> adjacency_;

        bool Dfs(Node current, Node target, std::set<Node>& visited) const {
            if (current == target) return true;
            if (!adjacency_.count(current) || visited.count(current)) return false;
            visited.insert(current);
            for (auto next : adjacency_.at(current)) {
                if (Dfs(next, target, visited)) return true;
            }
            return false;
        }

        bool HasCycleUtil(Node node, std::set<Node>& visited, std::set<Node>& recursion_stack) const {
            visited.insert(node);
            recursion_stack.insert(node);

            for (auto neighbor : adjacency_.at(node)) {
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
            std::set<Node> visited;
            std::set<Node> recursion_stack;

            for (const auto& [node, _] : adjacency_) {
                if (visited.count(node) == 0) {
                    if (HasCycleUtil(node, visited, recursion_stack)) return true;
                }
            }
            return false;
        }

        void TopoDfs(Node node, std::set<Node>& visited, std::vector<Node>& result) const {
            visited.insert(node);
            for (auto next : adjacency_.at(node)) {
                if (visited.count(next) == 0) {
                    TopoDfs(next, visited, result);
                }
            }
            result.push_back(node);
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const PriorityOrderingGraph& graph) {
        graph.Print(os);
        return os;
    }

} // namespace ecoscore::priority

#endif // ECOSCORE_PRIORITY_PRIORITY_ORDERING_GRAPH_H
