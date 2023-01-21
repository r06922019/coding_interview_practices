class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        ans = 0
        c = Counter(tasks)
        for k, v in c.items():
            if v < 2:
                return -1
            ans += math.ceil(v/3)
        return ans
