class Solution {
public:
    void init(vector<int> &dp) {
        assert(dp.size() == (1e4+1));
        if(dp[0] == 0) return ;
        dp[0] = 0;
        for(int i = 1; i <= 1e4; ++i) {
            for(int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }
    }

    int numSquares(int n) {
        static vector<int> dp(1e4+1, INT_MAX);
        init(dp);
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