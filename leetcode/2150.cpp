class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (auto num : nums)
        {
            ++counter[num];
        }

        vector<int> ans;
        for (auto num : nums)
        {
            if (counter[num] == 1 && counter.find(num - 1) == counter.end() && counter.find(num + 1) == counter.end())
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};