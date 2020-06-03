class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    bool match(int num1, int num2) {
        // return num1 > 2*num2; // prone to overflow
        int num1_half = num1 >> 1;
        return (num1_half > num2) || (num1_half == num2 && (num1 & 1));
    }

    // [4, 5] [1, 2] -> collect 1 for (4, 1), 2 for (5, 2), (5,1) => 3 in total
    int helper(vector<int> &nums, int start, int end) {
        if(end - start <= 1) return 0;

        int mid = start + (end-start)/2;
        int ans = helper(nums, start, mid) + helper(nums, mid, end);

        // merge, update ans
        int index1 = start, index2 = mid, index2_front = mid;
        vector<int> sorted;
        while(index1 < mid || index2 < end) {
            if(index2 >= end || (index1 < mid && nums[index1] < nums[index2])) {
                int &num1 = nums[index1];
                ++index1;
                sorted.push_back(num1);
                while(index2_front < end && match(num1, nums[index2_front])) {
                    ++index2_front;
                }
                ans += index2_front - mid;
            }
            else {
                sorted.push_back(nums[index2]);
                ++index2;
            }
        }
        for(int i = 0; i < end-start; ++i)
            nums[i+start] = sorted[i];
        return ans;
    }
};
