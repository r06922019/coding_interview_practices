class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        // while (num)
        // {
        //     num = (num & 1) ? num - 1 : num >> 1;
        //     ++count;
        // }
        for (; num; ++count)
            num = (num & 1) ? num - 1 : num >> 1;
        return count;
    }
};