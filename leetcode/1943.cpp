class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int max_end = 0;
        for(auto &s: segments) max_end = max(max_end, s[1]);
        vector<vector<long long>> table(max_end + 1, vector<long long>(2, 0));
        for(auto &s: segments) {
            int start = s[0];
            int end = s[1];
            int color = s[2];
            table[start][1] += color;
            table[end][0] -= color;
        }
        long long cur_score = 0;
        vector<vector<long long>> ans;
        vector<long long> cur;
        for(int i = 1; i <= max_end; ++i) {
            for(int j = 0; j < 2; ++j) {
                if(table[i][j]) {
                    if(cur.size()) {
                        cur.push_back(i);
                        cur.push_back(cur_score);
                        ans.push_back(cur);
                        cur.clear();
                    }
                    cur_score += table[i][j];
                }
            }
            if(cur_score && cur.empty())
                cur.push_back(i);
        }
        return ans;
    }
};