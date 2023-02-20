class Solution:
    def countOdds(self, low: int, high: int) -> int:
        d = high - low - 1
        if low % 2 == 0 and high % 2 == 0:
            return 1 + d//2
        if low % 2 == 1 and high % 2 == 0:
            return 1 + d//2
        if low % 2 == 0 and high % 2 == 1:
            return 1 + d//2
        if low % 2 == 1 and high % 2 == 1:
            return 2 + (d-1)//2
        return -1
