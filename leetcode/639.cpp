class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.size(), MOD = 1e9 + 7;
        vector<int> dp(n+1, 0); // dp[i] -> ways to decode len i
        dp[0] = 1; //
        for(int i = 1; i <= n; ++i) {
            char &cur_char = s[i-1];
            if(cur_char == '*') {
                // 1~9
                for(int j = 0; j < 9; ++j)
                    dp[i] = (dp[i] + dp[i-1]) % MOD;
                if(i - 2 >= 0) {
                    char &prev_char = s[i-2];
                    if(prev_char == '*') {
                        // 10~26 without 10, 20
                        for(int j = 0; j < 15; ++j)
                            dp[i] = (dp[i] + dp[i-2]) % MOD;
                    }
                    else {
                        if(prev_char == '1') {
                            for(int j = 11; j <= 19; ++j)
                                dp[i] = (dp[i] + dp[i-2]) % MOD;
                        }
                        else if(prev_char == '2') {
                            for(int j = 21; j <= 26; ++j)
                                dp[i] = (dp[i] + dp[i-2]) % MOD;
                        }
                    }
                }
            }
            else {
                int cur_digit = s[i-1] - '0';
                if(cur_digit != 0) dp[i] += dp[i-1];
                if(i - 2 >= 0) {
                    char &prev_char = s[i-2];
                    if(prev_char == '*') { // *2
                        for(int j = 1; j <= 2; ++j) {
                            if(j*10 + cur_digit <= 26) {
                                dp[i] = (dp[i] + dp[i-2]) % MOD;
                            }
                        }
                    }
                    else { // 23
                        int prev_digit = s[i-2] - '0';
                        int num = prev_digit * 10 + cur_digit;
                        if(num >= 10 && num <= 26)
                            dp[i] = (dp[i] + dp[i-2]) % MOD;
                    }
                }

            }
        }
        return dp[n];
    }
};