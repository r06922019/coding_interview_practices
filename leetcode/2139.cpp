class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        if (target == 1)
            return 0;
        else if (maxDoubles > 0)
        {
            return (target & 1) + 1 + minMoves(target >> 1, maxDoubles - 1);
        }
        else
            return target - 1;
    }
};