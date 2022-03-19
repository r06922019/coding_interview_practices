class Solution
{
public:
#define V vector
    double champagneTower(int poured, int query_row, int query_glass)
    {
        V<double> glasses(1, poured);
        while (query_row--)
        {
            int n = glasses.size();
            V<double> new_g(n + 1, 0);
            for (int i = 0; i < n; ++i)
            {
                if (glasses[i] >= 1)
                {
                    --glasses[i];
                    new_g[i] += glasses[i] / 2;
                    new_g[i + 1] += glasses[i] / 2;
                }
            }
            glasses = new_g;
        }
        return min(glasses[query_glass], 1.);
    }
};