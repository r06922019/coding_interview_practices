class Solution {
public:
    bool is_palin(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                palin[i][j] = is_palin(s, i, j);
            }
        }

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i < len; ++i) {
                // split string to s[0..i-1] (has length i) and s[i..len-1] (has length len-i)
                if(palin[i][len-1]) {
                    if(i > 0)
                        dp[len] = min(dp[len], dp[i] + 1);
                    else
                        dp[len] = 0;
                }
            }
        }
        return dp[n];
    }
};