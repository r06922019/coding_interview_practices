class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));

        // s&p both empty
        dp[0][0] = true;

        // p empty && s not empty, dp[0][j] remains false

        // p not empty && s empty, take care of dp[i][0]
        for(int i = 1; i <= p.size(); ++i) {
            if(p[i-1] == '*')
                dp[i][0] = dp[i-1][0];
        }

        for(int i = 1; i <= p.size(); ++i) {
            bool res = dp[i-1][0];
            for(int j = 1; j <= s.size(); ++j) {
                // dp[i][j]  s[i-1]  p[j-1]
                res = res | dp[i-1][j];
                char &cur_p = p[i-1], &cur_s = s[j-1];
                if(cur_p == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(isalpha(cur_p)) {
                    dp[i][j] = (cur_s == cur_p) && dp[i-1][j-1];
                }
                else {
                    // *
                    // for(int len = 0; len <= j; ++len) {
                    //     // * matches s.substr(j-len, len)
                    //     dp[i][j] = dp[i][j] | dp[i-1][j-len];
                    // }
                    dp[i][j] = res;
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
