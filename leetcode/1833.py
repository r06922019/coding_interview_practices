class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        ans = 0
        for x in sorted(costs):
            if coins >= x:
                ans += 1
                coins -= x
            else:
                break
        return ans
