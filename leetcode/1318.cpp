class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int cnt = 0;
        for (int i = 0; i < 31; ++i)
        {
            const int a_ = (1 << i) & a;
            const int b_ = (1 << i) & b;
            const int c_ = (1 << i) & c;
            if ((a_ | b_) != c_)
            {
                if (c_)
                {
                    ++cnt;
                }
                else
                {
                    if (a_)
                        ++cnt;
                    if (b_)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};