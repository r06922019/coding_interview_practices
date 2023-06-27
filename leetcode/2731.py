class Solution:
    def sumDistance(self, nums: List[int], s: str, d: int) -> int:
        n = len(nums)
        nums = sorted(
            [nums[i] + d if s[i] == 'R' else nums[i] - d for i in range(n)])
        diffs = [nums[i] - nums[i-1] for i in range(1, n)]
        ans = [diffs[i] * (i+1) * (n-(i+1)) for i in range(len(diffs))]
        return sum(ans) % (10**9+7)
