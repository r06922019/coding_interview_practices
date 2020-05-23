class Solution {
public:
    vector<string> parse_string(string &p) {
        vector<string> ret;
        for(char &c : p) {
            if(c != '*') {
                ret.push_back("");
            }
            ret.back() += c;
        }
        return ret;
    }

    bool isMatch(string s, string _p) {
        vector<string> p = parse_string(_p);
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));
        dp[0][0] = true;
        // dp[0][j] = false;
        // dp[i][0]
        for(int i = 1; i <= p.size(); ++i) {
            if(p[i-1].size() == 2)
                dp[i][0] = dp[i-1][0];
        }

        for(int i = 1; i <= p.size(); ++i) {
            string &cur_token = p[i-1];
            char &cur_p = cur_token[0];
            bool result = dp[i-1][0];
            for(int j = 1; j <= s.size(); ++j) {
                char &cur_s = s[j-1];
                if(isalpha(cur_p) && cur_p != cur_s) {
                    result = dp[i-1][j];
                }
                else { // . or equal
                    result = result || dp[i-1][j];
                }

                if(cur_token.size() == 1) {
                    dp[i][j] = (cur_p == '.' || cur_p == cur_s) && dp[i-1][j-1];
                }
                else { // a*
                    dp[i][j] = result;
                }
            }
        }

        return dp[p.size()][s.size()];
    }
};