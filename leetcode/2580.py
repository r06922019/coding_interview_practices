class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        parts = 1
        cur_a, cur_b = ranges[0]
        for r in ranges[1:]:
            a, b = r
            if cur_b >= a:
                cur_b = max(cur_b, b)
            else:
                cur_a, cur_b = a, b
                parts += 1
        ans = 1
        for _ in range(parts):
            ans = int((ans << 1) % (1e9+7))
        return ans
