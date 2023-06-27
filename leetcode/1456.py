class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a','e','i','o','u'}
        ans = v = r = 0
        for r in range(len(s)):
            if s[r] in vowels: v += 1
            if r >= k and s[r-k] in vowels: 
                v -= 1
            ans = max(ans, v)
        return ans
