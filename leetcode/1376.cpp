class Solution {
public:
    int numOfMinutes(int n, int head_id, vector<int>& manager_of, vector<int>& inform_time) {
        vector<vector<int>> adj_list(n, vector<int>());
        for(int i = 0; i < manager_of.size(); ++i) {
            if(i == head_id) continue;
            int &manager = manager_of[i];
            adj_list[manager].push_back(i);
        }

        int max_time = 0;
        queue<pair<int, int>> q;
        q.push({head_id, 0});
        while(q.size()) {
            int q_n = q.size();
            while(q_n--) {
                pair<int, int> cur_pair = q.front();
                q.pop();
                int &cur = cur_pair.first, &cur_time = cur_pair.second;
                max_time = max(max_time, cur_time);
                for(int &next : adj_list[cur]) {
                    q.push({next, cur_time + inform_time[cur]});
                }
            }
        }
        return max_time;
    }
};