class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], cur_min = nums[k];
        int l = k-1, r = k+1, n = nums.size();
        while(l >= 0 || r < n) {
            while(l >= 0 && nums[l] >= cur_min) --l;
            while(r < n && nums[r] >= cur_min) ++r;
            ans = max(ans, cur_min * (r-l-1));
            if(l >= 0 || r < n) {
                if(r >= n || (l >= 0 && nums[l] >= nums[r])) {
                    cur_min = nums[l];
                }
                else {
                    cur_min = nums[r];
                }
            }
        }
        return ans;
    }
};