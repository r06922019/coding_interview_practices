class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        c = Counter(nums)
        return sum([min(c[a], c[k-a]) for a in c if a < k/2]) + (c[k/2]//2 if k % 2 == 0 else 0)
