class Solution
{
public:
    int str_to_num(const string &str)
    {
        int num = 0;
        for (auto c : str)
        {
            const int index = c - 'a';
            const int mask = (1 << index);
            if (num & mask)
                return -1;
            num |= mask;
        }
        return num;
    }

    int count_set_bits(int x)
    {
        int count = 0;
        while (x)
        {
            ++count;
            x = x & (x - 1);
        }
        // for (int i = 0; i < 31; ++i)
        // {
        //     if (x & (1 << i))
        //         ++count;
        // }
        return count;
    }

    int maxLength(vector<string> &arr)
    {
        vector<int> choices;
        for (auto str : arr)
        {
            int num = str_to_num(str);
            if (num > 0)
            {
                choices.push_back(num);
            }
        }
        int ans = 0, n = choices.size();
        for (int cur_set = 0; cur_set < (1 << n); ++cur_set)
        {
            bool all_good = true;
            int cur_ans = 0;
            for (int i = 0; i < n && all_good; ++i)
            {
                if (cur_set & (1 << i))
                {
                    if ((choices[i] & cur_ans) == 0)
                    {
                        cur_ans |= choices[i];
                    }
                    else
                    {
                        all_good = false;
                    }
                }
            }
            if (all_good)
            {
                ans = max(ans, count_set_bits(cur_ans));
            }
        }
        return ans;
    }
};