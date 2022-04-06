class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        total_candies = sum(candies)
        if total_candies < k:
            return 0  # not enough candies

        def can_do(x):
            # piles = 0
            # for c in candies:
            #     piles += c // x
            # return piles >= k
            return sum([c//x for c in candies]) >= k

        l, r = 1, max(candies)+1
        while l < r:
            mid = (l+r)//2
            if can_do(mid):
                l = mid+1
            else:
                r = mid
        return l-1
