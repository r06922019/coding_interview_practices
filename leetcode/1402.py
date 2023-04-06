class Solution:
    def maxSatisfaction(self, sa: List[int]) -> int:
        sa.sort(reverse=True)
        ans, cur_sum = 0, 0
        for s in sa:
            if ans + cur_sum + s >= ans:
                ans += cur_sum + s
                cur_sum += s
            else:
                break
        return ans
