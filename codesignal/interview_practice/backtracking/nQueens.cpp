std::vector<std::vector<int>> nQueens(int n) {
    vector<vector<int>> ans;
    vector<int> cur;
    unordered_set<int> col_used, diag1_used, diag2_used;
    helper(cur, n, col_used, diag1_used, diag2_used, ans);
    return ans;
}

void helper(vector<int> &cur, int n, unordered_set<int> &col_used, unordered_set<int> &diag1_used, unordered_set<int> &diag2_used, vector<vector<int>> &ans) {

    if(cur.size() == n) {
        ans.push_back(cur);
        for(int &num : ans.back())
            ++num;
        return;
    }

    int row = cur.size();
    for(int col = 0; col < n; ++col) {
        if(col_used.find(col) == col_used.end()) {
            int diag1 = row+col;
            int diag2 = row-col;
            if(diag1_used.find(diag1) == diag1_used.end() && diag2_used.find(diag2) == diag2_used.end()) {
                col_used.insert(col);
                diag1_used.insert(diag1);
                diag2_used.insert(diag2);
                cur.push_back(col);
                helper(cur, n, col_used, diag1_used, diag2_used, ans);
                col_used.erase(col);
                diag1_used.erase(diag1);
                diag2_used.erase(diag2);
                cur.pop_back();
            }
        }
    }
    return ;
}