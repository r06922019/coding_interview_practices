class Solution {
public:
    unordered_map<int, int> dp = {{1,1},{0,1}};
    int numTrees(int n) {
        if(dp.find(n) != dp.end()) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans += numTrees(i-1) * numTrees(n-i);
        }
        dp[n] = ans;
        return ans;
    }
};