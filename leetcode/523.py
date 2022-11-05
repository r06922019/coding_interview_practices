class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        s = set()
        prev, cur = 0, 0
        for i, x in enumerate(nums):
            if i >= 1:
                s.add(prev)
            prev = cur
            cur = (cur+x) % k
            if cur in s:
                return True
        return False
