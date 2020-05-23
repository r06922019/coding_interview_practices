class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));
        dp[0][0] = true;
        // dp[0][j] = false
        // dp[i][0]
        for(int i = 1; i <= p.size(); ++i) {
            char &cur_p = p[i-1];
            if(cur_p == '*') {
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i <= p.size(); ++i) {
            char &cur_p = p[i-1];
            bool result = dp[i-1][0];
            for(int j = 1; j <= s.size(); ++j) {
                char &cur_s = s[j-1];
                result = result || dp[i-1][j];
                if(cur_p == '*') {
                    // OR { dp[i-1][x] for x from 0 to j }
                    dp[i][j] = result;
                }
                else {
                    dp[i][j] = (cur_p == '?' || (cur_p == cur_s)) && dp[i-1][j-1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};