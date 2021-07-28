enum class State {
    NOT_VISITED,
    IN_STACK,
    TRAVERSING,
    POPPED
};

class Solution {
public:
    bool has_cycle(int n, unordered_map<int, unordered_set<int>> &adj_lists) {
        vector<State> state(n+1, State::NOT_VISITED);
        for(int i = 1; i <= n; ++i) {
            if(state[i] == State::NOT_VISITED) {
                stack<int> st;
                st.push(i);
                state[i] = State::IN_STACK;
                while(st.size()) {
                    int cur = st.top();
                    if(state[cur] == State::IN_STACK) {
                        state[cur] = State::TRAVERSING;
                        for(auto &next : adj_lists[cur]) {
                            if(state[next] == State::NOT_VISITED) {
                                state[next] = State::IN_STACK;
                                st.push(next);
                            }
                            else if(state[next] == State::TRAVERSING) {
                                return true;
                            }
                        }
                    }
                    else if(state[cur] == State::TRAVERSING) {
                        state[cur] = State::POPPED;
                        st.pop();
                    }
                }
            }
        }
        return false;
    }

    void add_edge(unordered_map<int, unordered_set<int>> &adj_lists, vector<int> &edge,
                 vector<int> &in_degrees, int &root_candidate) {
        int a = edge[0], b = edge[1];
        adj_lists[a].insert(b);
        if(in_degrees[b] == 0)
            --root_candidate;
        ++in_degrees[b];
    }

    void erase_edge(unordered_map<int, unordered_set<int>> &adj_lists, vector<int> &edge,
                    vector<int> &in_degrees, int &root_candidate) {
        int a = edge[0], b = edge[1];
        adj_lists[a].erase(b);
        --in_degrees[b];
        if(in_degrees[b] == 0)
            ++root_candidate;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> in_degrees(n+1, 0);
        unordered_map<int, unordered_set<int>> adj_lists;
        int root_candidate = n;
        for(auto &edge : edges) {
            add_edge(adj_lists, edge, in_degrees, root_candidate);

        }
        reverse(edges.begin(), edges.end());
        for(auto &edge : edges) {
            erase_edge(adj_lists, edge, in_degrees, root_candidate);
            if(!has_cycle(n, adj_lists) \
               && root_candidate == 1 \
               && *max_element(in_degrees.begin(), in_degrees.end()) == 1) return edge;
            add_edge(adj_lists, edge, in_degrees, root_candidate);
        }
        return vector<int>();
    }
};