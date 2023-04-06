class Solution
{
public:
    const int N = 31;
    vector dp = vector(N, vector(N, vector<bool>(N, false)));
    vector visited = vector(N, vector(N, vector<bool>(N, false)));

    bool helper(const string &s1, const int &i1, const string &s2, const int &i2, const int &n)
    {
        if (visited[i1][i2][n])
            return dp[i1][i2][n];
        visited[i1][i2][n] = true;
        if (n == 1)
        {
            dp[i1][i2][n] = s1[i1] == s2[i2];
        }
        else if (n == 2)
        {
            dp[i1][i2][n] = (s1[i1] == s2[i2] && s1[i1 + 1] == s2[i2 + 1]) ||
                            (s1[i1 + 1] == s2[i2] && s1[i1] == s2[i2 + 1]);
        }
        else
        {

            bool result = false;
            for (int n1 = 1; n1 < n && !result; ++n1)
            {
                const int n2 = n - n1;
                result = result ||
                         (helper(s1, i1, s2, i2, n1) && helper(s1, i1 + n1, s2, i2 + n1, n2)) ||
                         (helper(s1, i1, s2, i2 + n2, n1) && helper(s1, i1 + n1, s2, i2, n2));
            }
            dp[i1][i2][n] = result;
        }
        return dp[i1][i2][n];
    }

    bool isScramble(string s1, string s2)
    {
        return helper(s1, 0, s2, 0, s1.size());
    }
};