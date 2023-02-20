class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        l, r = 0, len(nums)-1
        while l <= r:
            ans += int(str(nums[l])+str(nums[r])) if l < r else nums[l]
            l += 1
            r -= 1
        return ans
