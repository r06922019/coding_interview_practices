class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        l, r = 0, max(ranks) * cars * cars

        def can_do(t):
            c = 0
            for x in ranks:
                c += floor(math.sqrt(t/x))
            return c >= cars
        while l < r:
            mid = (l+r)//2
            if can_do(mid):
                r = mid
            else:
                l = mid+1
        return l
