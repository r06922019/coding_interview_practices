class Solution {
public:
    void helper(vector<int> &nums, int index, int target,
                vector<int> &buf,
                vector<vector<int>> &ans) {

        if(target <= 0) {
            if(target == 0) {
                ans.push_back(buf);
            }
            return;
        }

        for(int i = index; i < nums.size(); ++i) {
            if(nums[i] <= target) {
                buf.push_back(nums[i]);
                helper(nums, i, target-nums[i], buf, ans);
                buf.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> buf;
        vector<vector<int>> ans;
        helper(nums, 0, target, buf, ans);
        return ans;
    }
};