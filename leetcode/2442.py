class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        nums_str = [str(x) for x in nums] + [str(int(str(x)[::-1]))
                                             for x in nums]
        return len(set(nums_str))
