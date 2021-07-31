class Solution {
public:

    vector<string> tokenize(string &p) {
        vector<string> ans;
        for(auto &c : p) {
            if(c == '*') {
                ans.back() += c;
            }
            else {
                ans.push_back(string(1, c));
            }
        }
        return ans;
    }

    bool isMatch(string s, string _p) {
        vector<string> p = tokenize(_p);
        int m = p.size(), n = s.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i) {
            if(p[i-1].back() == '*') {
                dp[i][0] = dp[i-1][0];
            }
        }
        // for(int j = 1; j <= n; ++j) {
        //     dp[0][j] = false;
        // }
        for(int i = 1; i <= m; ++i) {
            auto &p_char = p[i-1][0];
            bool p_is_single = p[i-1].size() == 1;
            for(int j = 1; j <= n; ++j) {
                auto &s_char = s[j-1];
                if(p_is_single) {
                    if(p_char == '.' || p_char == s_char) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                else {
                    // matches empty
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                    if(p_char == '.' || p_char == s_char) {
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};