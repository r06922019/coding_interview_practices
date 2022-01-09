
class Solution
{
public:
    const char N = 'N', S = 'S', E = 'E', W = 'W';
    unordered_map<char, char> right = {
        {N, E}, {E, S}, {S, W}, {W, N}};
    unordered_map<char, char> left = {
        {N, W}, {W, S}, {S, E}, {E, N}};

    void go(int &x, int &y, char dir)
    {
        if (dir == S)
            --y;
        else if (dir == W)
            --x;
        else if (dir == N)
            ++y;
        else
            ++x;
    }

    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0, L = 0, R = 0;
        char dir = 'N';

        for (auto c : instructions)
        {
            if (c == 'G')
                go(x, y, dir);
            else if (c == 'L')
            {
                dir = left[dir];
                ++L;
            }
            else if (c == 'R')
            {
                dir = right[dir];
                ++R;
            }
        }
        return (x == 0 && y == 0) || (L % 4 != R % 4);
    }
};