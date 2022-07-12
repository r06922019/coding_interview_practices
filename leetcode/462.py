class Solution:
    def get_med(self, nums):
        nums = sorted(nums)
        ind = len(nums)//2
        return nums[ind]
    def minMoves2(self, nums: List[int]) -> int:
        med = self.get_med(nums)
        return sum([abs(med-x) for x in nums])
