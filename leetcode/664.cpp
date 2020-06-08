class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> cache(n+1, vector<int>(n+1, -1));
        return helper(s, 0, n, cache);
    }

    int helper(string &s, int start, int end, vector<vector<int>> &cache) {
        // min turns to print s.substr(start, end-start)
        // end -> exclusive
        if(end-start <= 1) {
            cache[start][end] = (end-start == 1)? 1:0;
            return cache[start][end];
        }

        if(cache[start][end] >= 0) return cache[start][end];

        int ans = helper(s, start, end-1, cache) + 1;
        for(int mid = start; mid < end-1; ++mid) {
            if(s[mid] == s[end-1]) {
                ans = min(ans, helper(s, start, mid+1, cache) + helper(s, mid+1, end-1, cache));
            }
        }
        cache[start][end] = ans;
        return cache[start][end];
    }
};