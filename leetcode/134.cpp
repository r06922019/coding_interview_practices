class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int min_index = -1, n = gas.size();
        vector<int> acc_sums = {0};
        for (int i = 0; i < n; ++i)
        {
            acc_sums.push_back(acc_sums.back() + gas[i] - cost[i]);
            if (min_index == -1 || acc_sums.back() < acc_sums[min_index + 1])
                min_index = i;
        }
        if (acc_sums.back() >= 0)
            return (min_index + 1) % n;
        return -1;
    }
};