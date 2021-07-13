class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int numSquares(int n) {
        int steps = 0;
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                int cur = q.front();
                q.pop();
                if(cur == n) return steps;
                for(int i = 1; (cur+i*i) <= n; ++i) {
                    int next = cur+i*i;
                    if(visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            ++steps;
        }
        return 0;
    }
};