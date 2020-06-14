class MaxScore {
public:
    int score, count;

    MaxScore() {
        count = score = 0;
    }

    MaxScore(int _s, int _c) {
        score = _s;
        count = _c;
    }

    vector<int> to_vec() {
        return {score, count};
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    void assign_if_higher_score(MaxScore &cur_result, MaxScore &prev_result, int &cur_score) {
        if(prev_result.count == 0) return;
        int new_score = prev_result.score + cur_score;
        if(cur_result.score < new_score) {
            cur_result.score = new_score;
            cur_result.count = prev_result.count;
        }
        else if(cur_result.score == new_score) {
            cur_result.count += prev_result.count;
            cur_result.count = cur_result.count % MOD;
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<MaxScore>> results(m, vector<MaxScore>(n));
        results[0][0].count = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                auto &cur_char = board[i][j];
                if(cur_char == 'X') continue;
                auto &cur_result = results[i][j];
                int cur_score = (isdigit(cur_char))? cur_char - '0':0;

                if(i > 0) {
                    assign_if_higher_score(cur_result, results[i-1][j], cur_score);
                }
                if(j > 0) {
                    assign_if_higher_score(cur_result, results[i][j-1], cur_score);
                }
                if(i > 0 && j > 0) {
                    assign_if_higher_score(cur_result, results[i-1][j-1], cur_score);
                }
            }
        }
        return results[m-1][n-1].to_vec();
    }
};