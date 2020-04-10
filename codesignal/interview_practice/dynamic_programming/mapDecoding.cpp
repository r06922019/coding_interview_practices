bool valid_single_char(char c) {
    return '1' <= c && c <= '9';
}

bool valid_double_char(char prev_char, char cur_char) {
    int prev_int = prev_char - '0';
    int cur_int = cur_char - '0';
    int num = prev_int * 10 + cur_int;
    return (10 <= num && num <= 26);
}

int mapDecoding(std::string message) {
    if(message.size() == 0) return 1;
    int MOD = 1000000000+7;
    vector<int> dp(message.size()+1, 0);
    // dp[n] -> ways first n chars can be decoded
    dp[0] = 1;
    dp[1] = (valid_single_char(message[0]))? 1:0;

    for(int i = 2; i <= message.size(); ++i) {
        // look at char @ i-1
        char cur_char = message[i-1];
        char prev_char = message[i-2];
        if(valid_single_char(cur_char)) {
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        if(valid_double_char(prev_char, cur_char)) {
            dp[i] = (dp[i] + dp[i-2]) % MOD;
        }
    }
    return dp.back();
}
