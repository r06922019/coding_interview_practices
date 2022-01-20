class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size() && n > 0; ++i)
        {
            if ((i == 0 || (i > 0 && flowerbed[i - 1] == 0)) && (i + 1 == flowerbed.size() || (i + 1 < flowerbed.size() && flowerbed[i + 1] == 0)) && flowerbed[i] == 0)
            {
                --n;
                flowerbed[i] = 1;
            }
        }
        return n == 0;
    }
};