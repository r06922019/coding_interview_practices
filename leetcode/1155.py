class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        prev = Counter([0])
        for _ in range(n):
            results = Counter()
            for i in prev:
                for j in range(1, k+1):
                    results[i+j] += prev[i]
            prev = results
        return prev[target] % int(1e9+7)
