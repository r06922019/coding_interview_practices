class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        ll, lr, r, ans = 0, 0, len(nums)-1, 0
        nums.sort()
        while ll < r:
            while lr < r and nums[lr] + nums[r] <= upper:
                lr += 1
            while ll < min(lr, r) and nums[ll] + nums[r] < lower:
                ll += 1
            ans += min(lr, r) - ll
            r -= 1
        return ans
