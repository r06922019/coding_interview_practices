class Solution
{
public:
    vector<int> gen_diffs(const vector<int> &vec)
    {
        vector<int> ret;
        for (int i = 1, n = vec.size(); i < n; ++i)
        {
            ret.push_back(vec[i] - vec[i - 1]);
        }
        return ret;
    }

    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        auto cmp = [](const int &a, const int &b)
        {
            return a > b;
        }; // min q uses greater
        priority_queue<int, vector<int>, decltype(cmp)> min_pq(cmp);
        vector<int> diffs = gen_diffs(heights);
        int index = 0, br_sum = 0;
        while (index < diffs.size())
        {
            auto diff = diffs[index];
            if (diff > 0)
            {
                min_pq.push(diff);
                while (min_pq.size() > ladders)
                {
                    br_sum += min_pq.top();
                    min_pq.pop();
                }
                if (br_sum > bricks)
                    break;
            }
            ++index;
        }
        return index;
    }
};