class Solution {
public:
    vector<vector<int>> get_costs(string &s) {
        int n = s.size();
        vector<vector<int>> costs(n, vector<int>(n, 0));
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i < n && i+len-1 < n; ++i) {
                if(len == 1) {
                    costs[i][i+len-1] = 0;
                }
                else {
                    // compare s[i] and s[i+len-1]
                    if(s[i] == s[i+len-1]) {
                        costs[i][i+len-1] = costs[i+1][i+len-2];
                    }
                    else {
                        costs[i][i+len-1] = costs[i+1][i+len-2]+1;
                    }
                }
            }
        }
        return costs;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> costs = get_costs(s);
        vector<vector<int>> dp(k+1, vector<int>(n+1, 200));
        for(int i = 0; i <= k; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 1; i <= k; ++i) {
            if(i == 1) {
                for(int len = 1; len <= n; ++len) {
                    dp[i][len] = costs[0][len-1];
                }
            }
            else {
                for(int len = 1; len <= n; ++len) {
                // partition first 'len' chars of s into 'i' parts
                    for(int j = 1; j < len; ++j) {
                        dp[i][len] = min(dp[i][len],
                                    dp[i-1][len-j] + costs[len-j][len-1]);
                        // i-th parts i has len j
                    }
                }
            }
        }
        return dp[k][n];
    }
};