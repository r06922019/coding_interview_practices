class Solution {
public:
    int MOD = pow(10, 9) + 7;
    void check_neighbor(vector<string>& board, int i, int j, int &max_score, int &max_count, vector<vector<vector<int>>> &dp) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == 'X') return ;

        if(dp[i][j][0] > max_score) {
            max_score = dp[i][j][0];
            max_count = dp[i][j][1];
        }
        else if(dp[i][j][0] == max_score) {
            max_count += dp[i][j][1];
            max_count = max_count % MOD;
        }

        return;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<vector<int>>> dp(board.size(), vector<vector<int>>(board[0].size(), vector<int>(2, 0)));

        dp[0][0][1] = 1; // E [0, 1] starts with score = 0, count = 1
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(isdigit(board[i][j]) || board[i][j] == 'S') {
                    int cur_score = (isdigit(board[i][j]))? board[i][j] - '0':0;
                    int max_score = 0, max_count = 0;

                    // see left
                    check_neighbor(board, i, j-1, max_score, max_count, dp);

                    // see left up
                    check_neighbor(board, i-1, j-1, max_score, max_count, dp);

                    // see up
                    check_neighbor(board, i-1, j, max_score, max_count, dp);

                    // save results
                    max_score += cur_score;
                    dp[i][j][0] = max_score;
                    dp[i][j][1] = max_count;
                }
            }
        }
        vector<int> ans = dp.back().back();
        if(ans[1] == 0) ans[0] = 0;
        return ans;
    }
};