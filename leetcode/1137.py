class Solution:
    def tribonacci(self, n: int) -> int:
        t = [0, 1, 1]
        while len(t) <= n:
            t.append(sum(t[-3:]))
        return t[n]
