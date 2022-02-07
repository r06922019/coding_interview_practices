class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int ans = 0, d = 0;
        unordered_map<int, int> diffs;
        diffs[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {

            //if(nums[i]==0) ++d;
            //else --d;
            const int m = (nums[i] - 1);
            d += ((~m) & 1) + m;

            auto it = diffs.find(d);
            if (it != diffs.end())
            {
                ans = max(ans, i - it->second);
            }
            else
            {
                diffs[d] = i;
            }
        }

        return ans;
    }
};