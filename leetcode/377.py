'''
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> cur(target+1, 0);
        cur[0] = 1;
        for(int i = 0; i < target; ++i) {
            for(auto num : nums) {
                if(i + num <= target) {
                    cur[i+num] += cur[i];
                }
            }
        }
        return cur[target];
    }
};
'''


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        cur = [0] * (target + 1)
        cur[0] = 1
        for i in range(0, target):
            for num in nums:
                if (i + num) <= target:
                    cur[(i+num)] += cur[i]
        return cur[target]
