class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for l in range(1, n):
            if n % l == 0 and s == s[:l] * (n//l):
                return True
        return False
