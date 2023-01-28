class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusts, trusted = Counter(), Counter()
        for a, b in trust:
            trusts[a] += 1
            trusted[b] += 1
        for i in range(1, n+1):
            if trusts[i] == 0 and trusted[i] == n-1:
                return i
        return -1
