class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        c = Counter([0])
        ans, cur = 0, 0
        for x in nums:
            cur += x
            ke = cur % k
            ans += c[ke]
            c[ke] += 1
        return ans
