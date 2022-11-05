class Solution
{
public:
    string countAndSay(int n)
    {
        string cur = "1";
        while (n-- > 1)
        {
            string next = "";
            for (int i = 0; i < cur.size();)
            {
                auto cur_char = cur[i];
                int cur_char_count = 0;
                while (i < cur.size())
                {
                    if (cur[i] == cur_char)
                    {
                        ++i;
                        ++cur_char_count;
                    }
                    else
                    {
                        break;
                    }
                }
                next += to_string(cur_char_count) + cur_char;
            }
            cur = next;
        }
        return cur;
    }
};