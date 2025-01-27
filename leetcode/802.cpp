class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        const int n = graph.size();
        vector<int> edge_counts(n, 0);
        vector<vector<int>> rev_graph(n, vector<int>());
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() == 0)
                q.push(i);
            for (const auto& nex : graph[i]) {
                rev_graph[nex].push_back(i);
                ++edge_counts[i];
            }
        }
        vector<int> safe_nodes;
        while (q.size()) {
            const auto cur = q.front();
            q.pop();
            safe_nodes.push_back(cur);
            for (const auto& prev : rev_graph[cur]) {
                --edge_counts[prev];
                if (edge_counts[prev] == 0)
                    q.push(prev);
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};
