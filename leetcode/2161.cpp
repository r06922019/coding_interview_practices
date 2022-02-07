class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> arr(nums.size(), pivot);
        int i = 0;
        for (auto num : nums)
        {
            if (num < pivot)
            {
                arr[i] = num;
                ++i;
            }
        }
        reverse(nums.begin(), nums.end());
        i = nums.size() - 1;
        for (auto num : nums)
        {
            if (num > pivot)
            {
                arr[i] = num;
                --i;
            }
        }
        return arr;
    }
};