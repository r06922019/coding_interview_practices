class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int steps = 0;
        while (target > startValue)
        {
            ++steps;
            if (target % 2)
                ++target;
            else
                target >>= 1;
        }
        return steps + startValue - target;
    }
};