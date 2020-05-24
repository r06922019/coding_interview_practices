class Solution {
public:
    string largestNumber(vector<int>& costs, int target) {
        vector<int> dp(target+1, -1); // length
        dp[0] = 0;
        for(int cur_cost = 0; cur_cost <= target; ++cur_cost) {
            if(dp[cur_cost] == -1) continue;
            for(int d = 1; d <= 9; ++d) {
                int new_cost = cur_cost + costs[d-1];
                int new_len = dp[cur_cost] + 1;
                const int &old_len = dp[new_cost];
                if(new_cost <= target && old_len < new_len) {
                    dp[new_cost] = dp[cur_cost] + 1;
                }
            }
        }
        if(dp[target] == -1) return "0";

        vector<char> ans;
        for(int d = 9; d >= 1; --d) {
            while((target - costs[d-1] >= 0) &&
                  dp[target] == dp[target - costs[d-1]] + 1) { // exists && valid (lens differ by 1)
                target -= costs[d-1];
                ans.push_back('0' + d);
            }
        }
        return string(ans.begin(), ans.end());
    }

    /*
    // O(T^2)
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
    */
};