class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                ss = s[i:j+1]
                pairs = 0
                for k in range(1, len(ss)):
                    if ss[k] == ss[k-1]:
                        pairs += 1
                if pairs <= 1:
                    ans = max(ans, len(ss))
        return ans
