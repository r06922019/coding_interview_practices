class Solution {
public:
    int get_lower_bound(vector<int> &nums, int m) {
        int s = 0;
        for(auto &num : nums) {
            s += num;
        }
        return s / m;
    }

    int get_upper_bound(vector<int> &nums, int m) {
        // split into m groups,
        // largest possible value would be a sum of the length(l - m + 1)
        int ans = 0, cur_sum = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i >= (n-m+1)) {
                cur_sum -= nums[i-(n-m+1)];
            }
            cur_sum += nums[i];
            ans = max(ans, cur_sum);
        }
        return ans;
    }

    bool can_achieve(vector<int> &nums, int max_sum, int m) {
        // want to split into groups with max sum <= max_sum
        // and the total groups <= m
        int groups = 1, cur_sum = 0;
        for(auto &num : nums) {
            if(num > max_sum) return false;
            if(cur_sum + num > max_sum) {
                ++groups;
                cur_sum = 0;
            }
            cur_sum += num;
        }
        return groups <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        // if we want to apply binary search, we need to have a upper bound
        int r = get_upper_bound(nums, m);
        // and a lower bound
        int l = get_lower_bound(nums, m);
        while(l < r) {
            int mid = l + (r-l)/2;
            if(can_achieve(nums, mid, m)) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};