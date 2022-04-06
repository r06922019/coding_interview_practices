class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        bitset<32> x(start ^ goal);
        return x.count();
    }
};