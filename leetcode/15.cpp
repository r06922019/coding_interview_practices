class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int cur_sum = nums[i] + nums[l] + nums[r];
                if(cur_sum > 0) {
                    --r;
                }
                else if(cur_sum < 0) {
                    ++l;
                }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int cur_l = nums[l];
                    while(l < r && nums[l] == cur_l) ++l;
                }
            }
        }
        return ans;
    }
};