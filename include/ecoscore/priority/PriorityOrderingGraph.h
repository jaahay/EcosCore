// src/ecoscore/priority/PriorityOrderingGraph.ixx
module ecoscore.priority.PriorityOrderingGraph;

#include <map>
#include <set>
#include <vector>
#include <stack>
#include <typeindex>
#include <stdexcept>
#include <iostream>
#include "ecoscore/type/StructType.h"

namespace ecoscore::priority {

    class PriorityOrderingGraph {
    public:
        using Node = const ecoscore::type::StructType*;

        void AddDependency(Node higher, Node lower) {
            if (higher == nullptr || lower == nullptr) {
                throw std::invalid_argument("PriorityOrderingGraph: null node");
            }
            adjacency_[higher].insert(lower);
            adjacency_[lower];

            if (HasCycle()) {
                adjacency_[higher].erase(lower);
                throw std::runtime_error("PriorityOrderingGraph: cycle detected");
            }
        }

        bool IsHigher(Node higher, Node lower) const {
            std::set<Node> visited;
            return Dfs(higher, lower, visited);
        }

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

}
