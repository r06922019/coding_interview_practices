class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.rbegin(), satisfaction.rend());
        if(*satisfaction.begin() < 0) return 0;
        int ans = 0, cur_sum = 0;
        for(auto &s : satisfaction) {
            if(ans + cur_sum + s >= ans) {
                ans += cur_sum + s;
                cur_sum += s;
            }
        }
        return ans;
    }
};