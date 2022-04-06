class Solution
{
public:
    int _minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int ans = -1, n = tops.size();
        for (int target = 1; target <= 6; ++target)
        {
            int cur_cost = 0;
            for (int i = 0; i < n && cur_cost >= 0; ++i)
            {
                if (tops[i] != target)
                {
                    if (bottoms[i] == target)
                        ++cur_cost;
                    else
                        cur_cost = -1;
                }
            }
            if (cur_cost != -1 && (ans == -1 || ans > cur_cost))
                ans = cur_cost;
        }
        return ans;
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int ans1 = _minDominoRotations(tops, bottoms);
        int ans2 = _minDominoRotations(bottoms, tops);
        if (ans1 == -1 && ans2 == -1)
            return -1;
        else if (ans1 == -1 || ans2 == -1)
            return max(ans1, ans2);
        return min(ans1, ans2);
    }
};