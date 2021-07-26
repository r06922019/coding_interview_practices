class Solution {
public:
    void helper(int cur, int k, int target, vector<int> &buf, vector<vector<int>> &ans) {
        if(target <= 0 || k == 0) {
            if(k == 0 && target == 0) {
                ans.push_back(buf);
            }
            return ;
        }

        for(int i = cur; i <= 9; ++i) {
            buf.push_back(i);
            helper(i+1, k-1, target-i, buf, ans);
            buf.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> buf;
        vector<vector<int>> ans;
        helper(1, k, target, buf, ans);
        return ans;
    }
};