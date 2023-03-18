class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        c = Counter(nums)
        return len(nums) - max(c.values())
