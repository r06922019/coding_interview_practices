class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        l = math.lcm(p, q)
        p, q = l/q, l/p
        if p % 2 == 1 and q % 2 == 0:
            return 0
        elif p % 2 == 0 and q % 2 == 1:
            return 2
        elif p % 2 == 1 and q % 2 == 1:
            return 1
        else:
            return -1
