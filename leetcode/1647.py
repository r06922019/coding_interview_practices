class Solution:
    def minDeletions(self, s: str) -> int:
        counts = sorted(Counter(s).values(), reverse=True)
        ans, target = 0, -1
        for count in counts:
            if target != -1 and target < count:
                ans += count - target
                count = target
            if count > 0:
                target = count-1
        return ans
