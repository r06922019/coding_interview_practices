class Solution {
public:
    int minimumDistance(string word) {
        int MAX_VAL = 10000;
        int n = word.size();
        if(n <= 2) return 0;
        vector<vector<int>> dp(n, vector<int>(26+1, MAX_VAL));
        dp[0][26] = 0;
        for(int i = 1; i < n; ++i) {
            // cur finger is on word[i-1]
            int cur_digit = word[i] - 'A', prev_digit = word[i-1] - 'A';
            int cur_finger_cost = get_distance(prev_digit, cur_digit);
            for(int j = 0; j < 27; ++j) { // if continue using cur finger
                dp[i][j] = min(MAX_VAL, dp[i-1][j] + cur_finger_cost);
            }

            // switch to use other finger
            int other_finger_cost = INT_MAX;
            for(int j = 0; j < 27; ++j) { // other finger was at j
                other_finger_cost = min(other_finger_cost, get_distance(j, cur_digit) + dp[i-1][j]);
            }

            // then current finger become other finger
            // other finger's position will be current finger's last position (prev_digit)
            int j = prev_digit;
            dp[i][j] = min(dp[i][j], other_finger_cost);
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }

    int get_distance(int a, int b) {
        // from a to b
        if(a == 26) return 0;
        int dx = (a/6) - (b/6);
        int dy = (a%6) - (b%6);
        return abs(dx) + abs(dy);
    }
};