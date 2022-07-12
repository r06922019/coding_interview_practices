class Solution:

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        self.dp = {}
        return self.isInterleaveInternal(s1, 0, s2, 0, s3, 0)

    def isInterleaveInternal(self, s1: str, i1: int, s2: str, i2: int, s3: str, i3: int) -> bool:
        if i3 == len(s3):
            return i1 == len(s1) and i2 == len(s2) and i3 == len(s3)

        cache_key = (i1, i2, i3)
        dp = self.dp
        if cache_key in dp:
            return dp[cache_key]
        dp[cache_key] = False

        if i1 < len(s1) and s1[i1] == s3[i3]:
            dp[cache_key] = dp[cache_key] or self.isInterleaveInternal(
                s1, i1+1, s2, i2, s3, i3+1)

        if i2 < len(s2) and s2[i2] == s3[i3]:
            dp[cache_key] = dp[cache_key] or self.isInterleaveInternal(
                s1, i1, s2, i2+1, s3, i3+1)

        return dp[cache_key]
