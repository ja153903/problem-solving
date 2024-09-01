#include <queue>
#include <utility>
#include <vector>

typedef std::pair<double, int> pq_t;
typedef std::vector<std::vector<pq_t>> graph_t;

class Solution {
  public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges,
                          std::vector<double>& probs, int start_node,
                          int end_node) {
        std::vector<double> prob(n, 0);
        auto graph = build_graph(n, edges, probs);

        std::priority_queue<pq_t, std::vector<pq_t>> pq;

        pq.push(std::make_pair(1.0, start_node));
        prob[start_node] = 1.0;

        while (!pq.empty()) {
            // pop the node with the largest probability from the queue
            const auto [cur_prob, cur_node] = pq.top();
            pq.pop();

            if (cur_node == end_node) {
                return cur_prob;
            }

            // for this current node, let's go through each of the neighbors
            for (const auto [next_prob, next_node] : graph[cur_node]) {
                auto new_prob = cur_prob * next_prob;
                if (new_prob > prob[next_node]) {
                    prob[next_node] = new_prob;
                    pq.push(std::make_pair(new_prob, next_node));
                }
            }
        }

        return 0.0;
    }

    graph_t build_graph(int n, std::vector<std::vector<int>>& edges,
                        std::vector<double>& probs) {
        graph_t graph(n);

        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            auto prob = probs[i];

            graph[edge[0]].push_back(std::make_pair(prob, edge[1]));
            graph[edge[1]].push_back(std::make_pair(prob, edge[0]));
        }

        return graph;
    }
};
