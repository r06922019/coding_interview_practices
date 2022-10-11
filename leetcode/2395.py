class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        return len(set([nums[i] + nums[i+1] for i in range(len(nums)-1)])) != len(nums)-1
