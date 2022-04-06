class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)//2
        indexs = sorted(list(range(n*2)),
                        key=lambda i: costs[i][0] - costs[i][1])
        # return sum([costs[i][0] for i in indexs[:n]] + [costs[i][1] for i in indexs[n : ]])
        return sum([costs[indexs[i]][0 if i < n else 1] for i in range(2*n)])
