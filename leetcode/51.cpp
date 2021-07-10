class Solution {
public:
    string empty_row = "";

    void helper(int row, int n,
                unordered_set<int> &col_used,
                unordered_set<int> &diag1_used,
                unordered_set<int> &diag2_used,
                vector<int> &buf, vector<vector<string>> &ans) {

        if(row == n) {
            vector<string> tmp_ans;
            for(auto &index : buf) {
                string s = empty_row;
                s[index] = 'Q';
                tmp_ans.push_back(s);
            }
            ans.push_back(tmp_ans);
            return;
        }

        for(int col = 0; col < n; ++col) {
            if(col_used.find(col) != col_used.end()) continue;
            int diag1 = row+col;
            if(diag1_used.find(diag1) != diag1_used.end()) continue;
            int diag2 = row-col;
            if(diag2_used.find(diag2) != diag2_used.end()) continue;

            col_used.insert(col), diag1_used.insert(diag1), diag2_used.insert(diag2);
            buf.push_back(col);
            helper(row+1, n, col_used, diag1_used, diag2_used, buf, ans);
            col_used.erase(col), diag1_used.erase(diag1), diag2_used.erase(diag2);
            buf.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> buf;
        unordered_set<int> col_used, diag1_used, diag2_used;
        for(int i = 0; i < n; ++i) {
            empty_row += ".";
        }
        helper(0, n, col_used, diag1_used, diag2_used, buf, ans);
        return ans;
    }
};