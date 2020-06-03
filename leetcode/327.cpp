class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> acc_num(n+1, 0);
        for(int i = 0; i < n; ++i) {
            acc_num[i+1] = acc_num[i] + nums[i];
        }

        return helper(acc_num, 0, acc_num.size(), lower, upper);
    }

    int helper(vector<long> &nums, int start, int end, int lower, int upper) {
        if(end-start <= 1) return 0;

        int mid = start + (end-start)/2;
        int cnt = 0;
        cnt += helper(nums, start, mid, lower, upper);
        cnt += helper(nums, mid, end, lower, upper);

        // update cnt
        for(int i = start, l = mid, r = mid; i < mid; ++i) {
            long &num = nums[i];
            // for each num, find appropriate l, r on the right side
            // s.t. nums[r] - num <= upper && nums[l] - num >= lower
            // update l
            while(l < end && nums[l] < lower + num)
                ++l;

            // update r
            while(r < end && nums[r] <= upper + num)
                ++r;

            // update count
            cnt += r-l;
        }

        // merge
        vector<long> sorted_nums;
        int i = start, j = mid;
        while(i < mid || j < end) {
            if(j == end || (i < mid && nums[i] < nums[j])) {
                sorted_nums.push_back(nums[i]);
                ++i;
            }
            else {
                sorted_nums.push_back(nums[j]);
                ++j;
            }
        }

        for(int i = start; i < end; ++i) {
            nums[i] = sorted_nums[i-start];
        }

        return cnt;
    }

};