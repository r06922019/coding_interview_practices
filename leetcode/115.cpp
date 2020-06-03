class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> cache(m+1, vector<int>(n+1, -1));
        for(int i = 0; i <= m; ++i)
            cache[i][n] = 1; // only 1 way from any s get to empty t
        for(int j = 0; j <= n; ++j)
            cache[m][j] = 0; // no way from empty s to any t
        cache[m][n] = 1; // empty s to empty t
        return helper(s, 0, t, 0, cache);
    }

    int helper(string &s, int i, string &t, int j, vector<vector<int>> &cache) {
        if(cache[i][j] >= 0)
            return cache[i][j];

        int ans = helper(s, i+1, t, j, cache); // skip s[i]
        if(s[i] == t[j]) {
            ans += helper(s, i+1, t, j+1, cache);
        }

        cache[i][j] = ans;
        return cache[i][j];
    }
};