class Solution
{
    public:
    //Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> in_degrees(n, 0);
        int visited = 0;

        for(int i = 0; i < n; ++i) {
            for(auto &next : adj[i]) {
                if(next == i) return true;
                ++in_degrees[next];
            }
        }

        for(int i = 0; i < n; ++i) {
            if(in_degrees[i] == 0) {
                q.push(i);
                ++visited;
            }
        }

        while(q.size()) {
            int cur = q.front();
            q.pop();
            for(auto &next : adj[cur]) {
                --in_degrees[next];
                if(in_degrees[next] == 0) {
                    q.push(next);
                    ++visited;
                }
            }
        }

        return visited < n;
    }
};