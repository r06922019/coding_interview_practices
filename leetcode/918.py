class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        if max(nums) <= 0:
            return max(nums)

        def kadane(nums: list[int]) -> tuple[int, int]:
            ans, cur_ans = max(nums), 0
            for x in nums:
                cur_ans = max(cur_ans+x, x)
                ans = max(ans, cur_ans)
            return ans
        ans1 = kadane(nums)
        ans2 = kadane([-x for x in nums])
        return max(ans1, sum(nums)+ans2)
