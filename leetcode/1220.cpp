class Solution {
public:

    const int MOD = 1e9+7;
    int add(const int &x, const int &y) {
        return ((x % MOD) + (y % MOD)) % MOD;
    }

    int countVowelPermutation(int n) {
/*
Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 0 may only be followed by an 1.
Each vowel 1 may only be followed by an 0 or an 2.
Each vowel 2 may not be followed by another 2.
Each vowel 3 may only be followed by an 2 or a 4.
Each vowel 4 may only be followed by an 0.

01, 10, 12, 20, 21, 23, 24, 32, 34, 40

10, 20, 40
01, 21
12, 32
23
24, 34

*/
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        vector<vector<int>> valid_prevs = {
            {1,2,4},
            {0,2},
            {1,3},
            {2},
            {2,3}
        };
        // dp[x][0] -> len x str ends at 'a'
        dp[1] = vector<int>(5, 1); // base case
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 5; ++j) {
                int tmp = 0;
                for(auto &prev : valid_prevs[j]) {
                    tmp = add(tmp, dp[i-1][prev]);
                }
                dp[i][j] = tmp;
            }
        }

        int ans = 0;
        for(int j = 0; j < 5; ++j) {
            ans = add(ans, dp[n][j]);
        }
        return ans;
    }
};