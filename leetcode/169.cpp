class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cand = 0, count = -1;
        for (auto num : nums)
        {
            if (count == -1 || (count == 0 && num != cand))
            {
                cand = num;
                count = 1;
            }
            else if (num == cand)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        return cand;
    }
};