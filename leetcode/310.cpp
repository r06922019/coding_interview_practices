class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return vector<int>();
        if(n == 1) return {0};
        vector<vector<int>> adj_lists(n);
        for(auto &edge : edges) {
            int &a = edge[0], &b = edge[1];
            adj_lists[a].push_back(b);
            adj_lists[b].push_back(a);
        }

        queue<int> q;
        vector<int> visited(n, 0), in_degrees(n);
        for(int i = 0; i < n; ++i) {
            if(adj_lists[i].size() == 1) {
                q.push(i);
                visited[i] = 1;
            }
            in_degrees[i] = adj_lists[i].size();
        }

        vector<int> ans_set;
        while(q.size()) {
            ans_set.clear();
            int q_size = q.size();
            while(q_size--) {
                int cur = q.front();
                q.pop();
                ans_set.push_back(cur);
                for(auto &next : adj_lists[cur]) {
                    --in_degrees[next];
                    if(!visited[next] && in_degrees[next] == 1) {
                        q.push(next);
                        visited[next] = 1;
                    }
                }
            }
        }

        return ans_set;
    }
};