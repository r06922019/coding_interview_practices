class Solution {
public:
    bool connected(unordered_map<int, unordered_set<int>> &adj_lists) {
        int n = adj_lists.size();
        unordered_set<int> visited{1};
        queue<int> q;
        q.push(1);
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                int cur = q.front();
                q.pop();
                for(auto &num : adj_lists[cur]) {
                    if(visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
            }
        }
        return visited.size() == n;
    }

    void add_edge(unordered_map<int, unordered_set<int>> &adj_lists,
                          vector<int> &edge) {
        int a = edge[0], b = edge[1];
        adj_lists[a].insert(b);
        adj_lists[b].insert(a);
    }

    void erase_edge(unordered_map<int, unordered_set<int>> &adj_lists,
                          vector<int> &edge) {
        int a = edge[0], b = edge[1];
        adj_lists[a].erase(b);
        adj_lists[b].erase(a);
    }

    bool connected(unordered_map<int, unordered_set<int>> &adj_lists, int start, int target) {
        unordered_set<int> visited{start};
        stack<int> s;
        s.push(start);
        while(s.size()) {
            int cur = s.top();
            s.pop();
            if(cur == target) return true;
            for(auto &next : adj_lists[cur]) {
                if(visited.find(next) == visited.end()) {
                    s.push(next);
                    visited.insert(next);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adj_lists;
        for(auto &edge : edges) {
            int a = edge[0], b = edge[1];
            if(connected(adj_lists, a, b)) return edge;
            add_edge(adj_lists, edge);
        }
        return vector<int>();
    }
};