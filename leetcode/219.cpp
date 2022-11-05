class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> val_to_index;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (val_to_index.find(nums[i]) != val_to_index.end())
            {
                if ((i - val_to_index[nums[i]]) <= k)
                    return true;
            }
            val_to_index[nums[i]] = i;
        }
        return false;
    }
};