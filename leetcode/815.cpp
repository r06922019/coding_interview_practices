
class Solution {
public:

    int bfs(int source_index, int target_index, vector<vector<int>> &bus_index_to_nodes, unordered_map<int, vector<int>> &node_index_to_buses) {

        if(source_index == target_index) return 0;

        queue<int> q;
        unordered_set<int> visited, bus_visited;

        for(int &bus_index : node_index_to_buses[source_index]) {
            if(bus_visited.find(bus_index) != bus_visited.end()) continue;
            for(int &index : bus_index_to_nodes[bus_index]) {
                if(visited.find(index) == visited.end()) {
                    q.push(index);
                    visited.insert(index);
                    bus_visited.insert(bus_index);
                }
            }
        }

        int moves = 1;
        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                int cur = q.front();
                q.pop();
                if(cur == target_index) return moves;
                // if it’s possible to change bus
                for(int &bus_index : node_index_to_buses[cur]) {
                    if(bus_visited.find(bus_index) != bus_visited.end()) continue;
                    for(int &index : bus_index_to_nodes[bus_index]) {
                        if(index == cur) continue; // skip same stop
                        if(visited.find(index) == visited.end()) {
                            q.push(index);
                            visited.insert(index);
                            bus_visited.insert(bus_index);
                        }
                    }
                }

            }
            ++moves;
        }

        return -1;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> node_index_to_buses;
        for(int i = 0; i < routes.size(); ++i) {
            for(int &stop : routes[i]) {
                node_index_to_buses[stop].push_back(i);
            }
        }
        return bfs(S, T, routes, node_index_to_buses);
    }
};

