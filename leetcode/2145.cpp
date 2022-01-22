class Solution
{
public:
    int numberOfArrays(vector<int> &diffs, int lower, int upper)
    {
        vector<long long> acc_sums = {0};
        for (auto diff : diffs)
        {
            acc_sums.push_back(acc_sums.back() + diff);
        }
        long long min_num = *min_element(acc_sums.begin(), acc_sums.end());
        long long max_num = *max_element(acc_sums.begin(), acc_sums.end());
        return max((long long)(upper - lower) - (max_num - min_num) + 1, (long long)0);
    }
};