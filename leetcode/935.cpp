class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> table(N, vector<int>(10, 0));
        // vector<vector<int>> neighbors = {
        //     {6,8}, {7,9}, {4,8}, {3, 9, 0}, {},
        //     {1, 7, 0}, {2,6}, {1,3}, {2,4}, {4,6}
        // };

        vector<vector<int>> parents = {
            {4,6}, {6,8}, {7,9}, {4,8}, {3, 9, 0},
            {}, {1, 7, 0}, {2,6}, {1,3}, {2,4}
        };

        int MOD = 1e9+7;
        for(int j = 0; j < 10; ++j) {
            table[0][j] = 1;
        }
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < 10; ++j) {
                int result = 0;
                for(int &parent : parents[j]) {
                    result = (result + table[i-1][parent]) % MOD;
                }
                table[i][j] = result;
            }
        }

        int ans = 0;
        for(int j = 0; j < 10; ++j) {
            ans = (ans + table[N-1][j]) % MOD;
        }
        return ans;
    }
};