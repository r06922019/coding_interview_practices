class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n)+str(2*n)+str(3*n)
        return not "0" in s and len(set(s)) == len(s)
