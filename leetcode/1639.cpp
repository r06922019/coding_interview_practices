class Solution {
public:
    const int MOD = 1e9+7;

    int add(const int &x, const int &y) {
        return ((x % MOD) + (y % MOD)) % MOD;
    }

    int mul(const int &base, int mul) {
        int ans = 0;
        int cur = base % MOD;
        while(mul) {
            if(mul & 1) {
                ans = add(ans, cur);
            }
            mul = mul >> 1;
            cur = (cur * 2) % MOD;
        }
        return ans;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int len = target.size();
        if(len > n) return 0;

        vector<vector<int>> index_to_chars(n, vector<int>(26, 0));
        for(auto &word : words) {
            for(int i = 0; i < n; ++i) {
                char &c = word[i];
                ++index_to_chars[i][c - 'a'];
            }
        }

        vector<vector<int>> dp(len+1, vector<int>(n+1, 0));
        dp[0] = vector<int>(n+1, 1); // base case, "" can be formed with len = 0 words
        for(int i = 1; i <= len; ++i) {
            const char &cur_char = target[i-1];
            for(int j = 1; j <= n; ++j) {
                int count = index_to_chars[j-1][cur_char - 'a'];
                dp[i][j] = add(mul(dp[i-1][j-1], count), dp[i][j-1]);
            }
        }
        return dp[len][n];
    }
};