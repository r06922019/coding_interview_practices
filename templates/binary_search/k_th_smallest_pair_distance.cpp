class Solution {
public:
    int min_diff_in_array(vector<int>& nums) {
        int ret = INT_MAX;
        for(int i = 1; i < nums.size(); ++i) {
            ret = min(ret, nums[i]-nums[i-1]);
        }
        return ret;
    }

    int max_diff_in_array(vector<int>& nums) {
        return nums.back()-nums.front();
    }

    // will get the first true at the real answer
    bool filter_func(vector<int> &nums, int x, int k) {
        int cnt = 0;
        int r = 0;
        for(int l = 0; l < nums.size(); ++l) {
            while(r < nums.size() && (nums[r] - nums[l]) <= x)
                ++r;
            cnt += r-1-l;
        }
        // cnt is number of results that are <= x
        return cnt >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = min_diff_in_array(nums);
        int r = max_diff_in_array(nums);
        while(l < r) {
            int mid = l + (r-l)/2;
            if(filter_func(nums, mid, k)) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};