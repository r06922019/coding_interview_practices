class Solution:
    def longestSubsequence(self, arr: List[int], d: int) -> int:
        ans = Counter()
        for x in arr:
            ans[x] = max(ans[x], ans[x-d]+1)
        return max(ans.values())
