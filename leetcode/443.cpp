class Solution
{
public:
    int compress(vector<char> &chars)
    {
        const int n = chars.size();
        if (n <= 1)
            return n;
        int len = 0, l = 0;
        while (l < n)
        {
            const char c = chars[l];
            int r = l;
            while (r < n && chars[r] == c)
                ++r;
            const int cnt = r - l;
            chars[len++] = c;
            if (cnt > 1)
            {
                const auto cnt_str = to_string(cnt);
                copy(cnt_str.c_str(), cnt_str.c_str() + cnt_str.size(), chars.begin() + len);
                len += cnt_str.size();
            }
            l = r;
        }
        return len;
    }
};