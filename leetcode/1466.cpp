class Road {
public:
    int dest, cost;
    Road () {
        dest = cost = -1;
    }

    Road(int d, int c) {
        dest = d;
        cost = c;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // unordered_map<int, vector<Road>> adj_list;
        vector<vector<Road>> adj_list(n, vector<Road>());
        for(auto &conn : connections) {
            int &a = conn[1], &b = conn[0];
            adj_list[a].emplace_back(b, 0);
            adj_list[b].emplace_back(a, 1);
        }

        int cost = 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            for(auto &r : adj_list[cur]) {
                int &dest = r.dest;
                if(!visited[dest]) {
                    visited[dest] = true;
                    cost += r.cost;
                    q.push(dest);
                }
            }
        }
        return cost;
    }
};