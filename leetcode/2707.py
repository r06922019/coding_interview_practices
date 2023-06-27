class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        # dp = [100] * (len(s)+1)
        # def solve(index):
        #     if dp[index] != 100: return dp[index]
        #     ans = len(s) - index
        #     for i in range(index, len(s)):
        #         for w in dictionary:
        #             if i+len(w) <= len(s) and s[i:i+len(w)] == w:
        #                 ans = min(ans, i-index + solve(i+len(w)))
        #     dp[index] = ans
        #     return ans
        # return solve(0)
        dp = list(range(len(s)+1))
        for l in range(len(s)+1):
            for i in range(l):
                dp[l] = min(dp[l], dp[i]+l-i)
            for w in dictionary:
                if len(w) <= l and s.endswith(w):
                    dp[l] = min(dp[l], dp[l-len(w)])
        return dp[len(s)]
