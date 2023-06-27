class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans, l, r = 0, 0, len(nums)-1
        while l <= r and nums[l] <= target // 2:
            while l < r and nums[l] + nums[r] > target:
                r -= 1
            ans += 2 ** (r-l)
            l += 1
        return ans % (10**9+7)
