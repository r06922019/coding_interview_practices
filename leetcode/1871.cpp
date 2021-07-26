class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // queue<int> q;
        // vector<bool> visited(s.size(), false);
        // q.push(0);
        // visited[0] = true;
        // while(q.size()) {
        //     int q_size = q.size();
        //     while(q_size--) {
        //         int cur = q.front();
        //         q.pop();
        //         for(int i = cur + minJump;
        //             i <= cur + maxJump && i < s.size(); ++i) {
        //             if(s[i] == '0' && !visited[i]) {
        //                 q.push(i);
        //                 visited[i] = true;
        //             }
        //         }
        //     }
        // }
        // return visited.back();
        if(s.back() != '0') return false;
        int n = s.size(), prev_sum = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i) {
            // we can only reach dp[i] if s[i] == '0' and
            // we have any true at dp[i-maxJump ... i-minJump] -> stored in prev_sum

            // for i, prev_sum stores dp[i-maxJump-1 ... i-minJump-1]
            // so
            if(i-maxJump-1 >= 0 && dp[i-maxJump-1]) { // pop i-maxJump-1
                --prev_sum;
            }
            if(i-minJump >= 0 && dp[i-minJump]) { // push i-minJump
                ++prev_sum;
            }
            if(s[i] == '0' && prev_sum > 0) {
                dp[i] = true;
            }
        }
        return dp[n-1];
    }
};