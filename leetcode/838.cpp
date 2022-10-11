class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        const auto char R = 'R', L = 'L';
        vector<int> r_distances(n, -1), l_distances(n, -1);
        for (int i = 0, r = -1; i < n; ++i)
        {
            if (dominoes[i] == R)
            {
                r = i;
            }
            else if (dominoes[i] == L)
            {
                r = -1;
            }
            else if (dominoes[i] == '.' && r != -1)
            {
                r_distances[i] = i - r;
            }
        }
        for (int i = n - 1, l = -1; i >= 0; --i)
        {
            if (dominoes[i] == L)
            {
                l = i;
            }
            else if (dominoes[i] == R)
            {
                l = -1;
            }
            else if (dominoes[i] == '.' && l != -1)
            {
                l_distances[i] = l - i;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (dominoes[i] == '.')
            {
                if (l_distances[i] == -1 && r_distances[i] != -1)
                {
                    dominoes[i] = R;
                }
                else if (l_distances[i] != -1 && r_distances[i] == -1)
                {
                    dominoes[i] = L;
                }
                else
                {
                    if (l_distances[i] < r_distances[i])
                    {
                        dominoes[i] = L;
                    }
                    else if (l_distances[i] > r_distances[i])
                    {
                        dominoes[i] = R;
                    }
                }
            }
        }
        return dominoes;
    }
};