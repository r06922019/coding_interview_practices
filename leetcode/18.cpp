class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return k_sum(nums, target, 4);
    }

    vector<vector<int>> k_sum(vector<int> &nums, int target, int k) {
        sort(nums.begin(), nums.end());
        return k_sum_helper(nums, target, 4, 0, nums.size());
    }

    vector<vector<int>> k_sum_helper(vector<int> &nums, int target, int k, int start, int end) {
        vector<vector<int>> ans;
        if((end-start) < k) return ans;
        if(k == 2) {
            int l = start, r = end-1;
            while(l < r) {
                int cur_sum = nums[l] + nums[r];
                if(cur_sum == target) {
                    ans.push_back({nums[l], nums[r]});
                }
                if(cur_sum < target) {
                    int &cur_num = nums[l];
                    while(l < r && nums[l] == cur_num) ++l;
                }
                else {
                    int &cur_num = nums[r];
                    while(l < r && nums[r] == cur_num) --r;
                }
            }
            return ans;
        }
        for(int i = start; i < end; ++i) {
            if(i != start && nums[i] == nums[i-1]) continue;
            int &cur_num = nums[i];
            for(auto &vec : k_sum_helper(nums, target-cur_num, k-1, i+1, end)) {
                ans.push_back({cur_num});
                for(int &num : vec) {
                    ans.back().push_back(num);
                }
            }
        }
        return ans;
    }
};


/*

[1, 0, -1, 0, -2, 2]

-2, -1, 0, 0, 1, 2

*/