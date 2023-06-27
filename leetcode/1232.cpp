class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coords)
    {
        auto a = coords[0], c = coords.back();
        const auto n = coords.size();
        for (int i = 1; i + 1 < n; ++i)
        {
            auto b = coords[i];
            // (b[1]-a[1])/(b[0]-a[0]) == (c[1]-a[1])/(c[0]-a[0])
            const auto ba0 = (b[0] - a[0]), ca0 = (c[0] - a[0]);
            const auto ba1 = (b[1] - a[1]), ca1 = (c[1] - a[1]);
            if (ba0 == 0 && ca0 == 0)
                continue;
            else if (ba0 == 0 || ca0 == 0)
                return false;
            else if (ba1 * ca0 != ba0 * ca1)
                return false;
        }
        return true;
    }
};