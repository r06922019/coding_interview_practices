class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size(), index = 0, good = 0;
        for (int i = 0, cur_good = 0; i < n; ++i)
        {
            if (customers[i] == 'Y')
                ++cur_good;
            else
                --cur_good;
            if (cur_good > good)
                index = i + 1, good = cur_good;
        }
        return index;
    }
};