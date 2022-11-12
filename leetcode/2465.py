class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        l = []
        nums.sort()
        i, j = 0, len(nums)-1
        while i < j:
            avg = (nums[i] + nums[j])/2
            l.append(avg)
        return len(Counter(l))
