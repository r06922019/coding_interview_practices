class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        c = Counter([nums[i]-i for i in range(len(nums))])
        return sum(x*(len(nums)-x) for x in c.values()) // 2
