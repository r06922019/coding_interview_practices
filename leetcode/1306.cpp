class Solution {
public:
    bool is_valid(vector<int> &arr, int index) {
        return index >= 0 && index < arr.size();
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                int cur = q.front();
                q.pop();
                for(auto &next : {cur + arr[cur], cur - arr[cur]}) {
                    if(is_valid(arr, next) && !visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if(arr[i] == 0 && visited[i])
                return true;
        }
        return false;
    }
};