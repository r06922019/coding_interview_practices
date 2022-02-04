class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        vector<int> left(seats.size(), seats.size()), right(seats.size(), seats.size());
        for (int i = 0; i < seats.size(); ++i)
        {
            if (seats[i] == 1)
                left[i] = 0;
            else if (i > 0 && left[i - 1] != seats.size())
                left[i] = left[i - 1] + 1;
        }

        for (int i = seats.size() - 1; i >= 0; --i)
        {
            if (seats[i] == 1)
                right[i] = 0;
            else if (i + 1 < right.size() && right[i + 1] != seats.size())
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < seats.size(); ++i)
        {
            ans = max(ans, min(left[i], right[i]));
        }
        return ans;
    }
};