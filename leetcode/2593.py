class Solution:
    def findScore(self, nums: List[int]) -> int:
        sorted_nums = sorted([(num, i) for i, num in enumerate(nums)])
        score = 0
        for (num, i) in sorted_nums:
            if nums[i]:
                score += num
                if i+1 < len(nums):
                    nums[i+1] = 0
                if i-1 >= 0:
                    nums[i-1] = 0
        return score
