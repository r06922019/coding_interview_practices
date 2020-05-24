class Solution {
public:

    bool is_better(string &old_str, string &new_str) {
        if(old_str.empty()) return true;
        if(new_str.empty()) return false;

        if(old_str.size() < new_str.size()) {
            return true;
        }
        else if(old_str.size() == new_str.size()) {
            return old_str < new_str;
        }
        return false;
    }

    string largestNumber(vector<int>& costs, int target) {
        vector<string> dp(target+1, "");

        for(int digit = 1; digit <= 9; ++digit) {
            int cur_cost = costs[digit-1];
            if(cur_cost <= target) {
                dp[cur_cost] = to_string(digit);
            }
        }

        for(int cur_cost = 1; cur_cost <= target; ++cur_cost) {
            if(dp[cur_cost].size()) {
                for(int digit = 1; digit <= 9; ++digit) {
                    int new_cost = cur_cost + costs[digit-1];
                    if(new_cost <= target) {
                        string new_str = dp[cur_cost] + to_string(digit);
                        if(is_better(dp[new_cost], new_str)) {
                            dp[new_cost] = new_str;
                        }
                    }
                }
            }
        }
        return (dp[target].empty())? "0":dp[target];
    }
};