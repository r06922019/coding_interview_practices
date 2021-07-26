class Solution {
public:
    void enqueue_if_valid_and_unvisited(int index, vector<int>& arr,
                                        queue<int> &q, vector<bool> &visited) {
        if(index >= 0 && index < arr.size() && !visited[index]) {
            visited[index] = true;
            q.push(index);
        }
    }

    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> value_to_indexs;
        for(int i = 0; i < n; ++i) {
            value_to_indexs[arr[i]].push_back(i);
        }

        int steps = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        if(visited[n-1]) return steps;
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                int cur = q.front();
                // printf("%d ", cur);
                q.pop();
                enqueue_if_valid_and_unvisited(cur-1, arr, q, visited);
                enqueue_if_valid_and_unvisited(cur+1, arr, q, visited);
                for(auto &next : value_to_indexs[arr[cur]])
                    enqueue_if_valid_and_unvisited(next, arr, q, visited);
                value_to_indexs[arr[cur]].clear(); // ensure only expanded once
            }
            ++steps;
            if(visited[n-1]) return steps;
            // puts("");
        }
        return -1;
    }
};