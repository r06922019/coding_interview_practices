class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; ++i) {
            char &c1 = str1[i-1];
            for(int j = 1; j <= n; ++j) {
                char &c2 = str2[j-1];
                if(c1 == c2) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        vector<char> ans;
        int i = m, j = n;
        while(i > 0 || j > 0) {
            if(i > 0 && j > 0) {
                char &c1 = str1[i-1], &c2 = str2[j-1];
                if(c1 == c2) {
                    ans.push_back(c1);
                    --i;
                    --j;
                }
                else {
                    if(dp[i-1][j] > dp[i][j-1]) {
                        ans.push_back(c1);
                        --i;
                    }
                    else {
                        ans.push_back(c2);
                        --j;
                    }
                }
            }
            else if(i > 0) {
                char &c1 = str1[i-1];
                ans.push_back(c1);
                --i;
            }
            else {
                char &c2 = str2[j-1];
                ans.push_back(c2);
                --j;
            }
        }
        return string(ans.rbegin(), ans.rend());
    }
};