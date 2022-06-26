class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        l = ans = cur_sum = 0
        seen = set()
        for r in range(len(nums)):
            while nums[r] in seen:
                seen.remove(nums[l])
                cur_sum -= nums[l]
                l += 1
            seen.add(nums[r])
            cur_sum += nums[r]
            ans = max(ans, cur_sum)
        return ans
