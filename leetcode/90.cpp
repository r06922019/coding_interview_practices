class Solution {
public:

    void helper(vector<int> &nums, int index, vector<int> &cur_set, vector<vector<int>> &ans) {
        if(index == nums.size()) {
            ans.push_back(cur_set);
            return;
        }
        int next_index = index, cur = nums[index];
        while(next_index < nums.size() && nums[next_index] == cur)
            ++next_index;

        helper(nums, next_index, cur_set, ans);
        for(int i = 0; i < next_index - index; ++i) {
            cur_set.push_back(cur);
            helper(nums, next_index, cur_set, ans);
        }
        for(int i = 0; i < next_index - index; ++i)
            cur_set.pop_back();
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur_set;
        helper(nums, 0, cur_set, ans);
        return ans;
    }
};
