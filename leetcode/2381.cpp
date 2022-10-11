class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int> > &shifts)
    {
        vector<int> results(s.size() + 1, 0);
        for (auto vec : shifts)
        {
            auto start = vec[0], end = vec[1] + 1, dir = vec[2];
            if (dir == 0)
                dir = -1;
            results[start] += dir;
            results[end] -= dir;
        }
        int cur = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            cur += results[i];
            int cur_char = s[i] - 'a';
            if (cur < 0)
            {
                cur = 26 + (-1 * (-cur) % 26);
            }
            cur_char = (cur_char + cur) % 26;
            s[i] = 'a' + cur_char;
        }
        return s;
    }
};