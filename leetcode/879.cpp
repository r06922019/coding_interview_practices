/*
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        cache = {}
        def solve(n:int, minProfit:int, end:int):
            if end == 0: return 1 if minProfit <= 0 and n >= 0 else 0
            cache_key = (n,minProfit,end)
            if cache_key in cache: return cache[cache_key]
            i = end-1
            cache[cache_key] = solve(n-group[i], minProfit-profit[i],end-1) + solve(n, minProfit,end-1)
            return cache[cache_key]

        return solve(n, minProfit, len(group))
*/

class Solution
{
public:
    const int MOD = 1e9 + 7;
    // const int N = 100, M = 100, P = 100;
    // vector<vector<vector<int>>> cache = vector<vector<vector<int>>>(N+1, vector<vector<int>>(M+1, vector<int>(P+1, -1)));
    array<array<array<int, 101>, 101>, 101> cache;

    int helper(const int n, const int minProfit, const int len, vector<int> &group, vector<int> &profit)
    {
        // printf("start (%d,%d,%d)\n", n, minProfit, len);
        if (n < 0)
            return 0;
        if (minProfit < 0)
            return 1;
        if (len == 0)
            return (minProfit == 0 && n >= 0) ? 1 : 0;
        if (cache[n][minProfit][len] != -1)
            return cache[n][minProfit][len];
        const auto i = len - 1;
        cache[n][minProfit][len] = ((helper(n - group[i], max(0, minProfit - profit[i]), len - 1, group, profit) % MOD) +
                                    (helper(n, minProfit, len - 1, group, profit) % MOD)) %
                                   MOD;
        // printf("end (%d,%d,%d) = %d\n", n, minProfit, len, cache[n][minProfit][len]);
        return cache[n][minProfit][len];
    }

    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 101; ++j)
                for (int k = 0; k < 101; ++k)
                    cache[i][j][k] = -1;
        return helper(n, minProfit, group.size(), group, profit);
    }
};