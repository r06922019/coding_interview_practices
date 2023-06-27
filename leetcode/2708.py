class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        ans = 1
        for x in nums:
            ans = ans * x
        for mask in range(1, int(1 << len(nums))):
            tmp = 1
            for b in range(len(nums)):
                if mask & (1 << b):
                    tmp *= nums[b]
            ans = max(ans, tmp)
        return ans
