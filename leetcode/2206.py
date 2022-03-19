class Solution(object):
    def divideArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        counter = Counter(nums)
        for count in counter.values():
            if count % 2 != 0:
                return False
        return True
