vector<string> preprocess_patterns(string s) {
    vector<string> vec;
    for(auto &c : s) {
        if(c != '*') {
            vec.push_back(string(1, c));
        }
        else {
            vec.back().push_back(c);
        }
    }
    return vec;
}

bool regularExpressionMatching(string s, string _p) {
    vector<string> p = preprocess_patterns(_p);
    int m = p.size(), n = s.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= m; ++i) {
        if(p[i-1].back() == '*') {
            dp[i][0] = dp[i-1][0]; // match 0
        }
    }
    for(int i = 0; i < m; ++i) {
        auto &c = p[i][0];
        for(int j = 0; j < n; ++j) {
            if(p[i].size() == 1 && (c == s[j] || c == '.')) { // match single
                dp[i+1][j+1] = dp[i][j];
            }
            else if(p[i].size() == 2) { // * case
                dp[i+1][j+1] = dp[i][j+1]; // match 0, pattern pop back
                if(c == s[j] || c == '.') { // match single, can "freely" pop string back
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j];
                }
            }
        }
    }
    return dp[m][n];
}
