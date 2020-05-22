class Solution {
public:
    vector<string> reparse(string p) {
        vector<string> ret;
        int index = 0;
        while(index < p.size()) {
            ret.push_back(p.substr(index, 1));
            ++index;
            if(index < p.size() && p[index] == '*') {
                ret.back() += p[index];
                ++index;
            }
        }
        return ret;
    }

    bool isMatch(string s, string _p) {
        vector<string> p = reparse(_p);
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));

        dp[0][0] = true;

        // p empty && s not empty, dp[0][j] -> false
        // p not empty && s empty, dp[i][0]
        for(int i = 1; i <= p.size(); ++i) {
            string &token = p[i-1];
            char &c = token[0];
            if(token.size() == 1) {
                if(isalpha(c)) {
                    dp[i][0] = false;
                }
                else { // ‘.’
                    dp[i][0] = false;
                }
            }
            else { // .*
                // c can repeat 0 times
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i <= p.size(); ++i) {
            string &token = p[i-1];
            char &c = token[0];
            bool result = dp[i-1][0];
            for(int j = 1; j <= s.size(); ++j) {
                // chech if c matches s[j-1]
                // if not, overwrite result
                if(isalpha(c) && c != s[j-1]) {
                    // printf("%d %d not match\n", i-1, j-1);
                    result = dp[i-1][j];
                }
                else {
                    result = result || dp[i-1][j];
                }

                if(token.size() == 1) {
                    if(isalpha(c)) {
                        dp[i][j] = (c == s[j-1]) && dp[i-1][j-1];
                    }
                    else { // ‘.’
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                else { // .*
                    // c can repeat 0~j times
                    // c* aaabbccccc
                    // int tmp_index = j-1;
                    // while(tmp_index >= 0 && matches(c, s[tmp_index)) --tmp_index;
                    // if(tmp_index == -1) result = true;
                    // else result = dp[i-1][tmp_index+1];
                    dp[i][j] = result;
                }
            }
        }

        // print_mat(p, s, dp);
        return dp[p.size()][s.size()];
    }

    void print_mat(vector<string> &p, string &s, vector<vector<bool>> &dp) {
        cout << "   - ";
        for(int j = 0; j < s.size(); ++j) {
            cout << s[j] << " ";
        }
        cout << endl;
        for(int i = 0; i <= p.size(); ++i) {
            if(i > 0) {
                if(p[i-1].size() == 1)
                    cout << p[i-1] << "  ";
                else
                    cout << p[i-1] << " ";
            }
            else
                cout << "-  ";
            for(int j = 0; j <= s.size(); ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};
