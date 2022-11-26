class Solution
{
public:
    void rewrite_time(vector<int> &s, vector<int> &e, int n)
    {
        set<int> timeSet;
        for (int i = 0; i < n; ++i)
        {
            timeSet.insert(s[i]);
            timeSet.insert(e[i]);
        }
        unordered_map<int, int> old2new;
        for (auto oldTime : timeSet)
        {
            old2new[oldTime] = old2new.size();
        }
        for (int i = 0; i < n; ++i)
        {
            s[i] = old2new[s[i]];
            e[i] = old2new[e[i]];
        }
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();
        rewrite_time(startTime, endTime, n);
        unordered_map<int, vector<int>> endTime2Index;
        for (int i = 0; i < n; ++i)
        {
            endTime2Index[endTime[i]].push_back(i);
        }
        vector<int> dp(*max_element(endTime.begin(), endTime.end()) + 1, 0);
        for (int e = 1; e < dp.size(); ++e)
        {
            dp[e] = dp[e - 1];
            auto endTimesIndexs = endTime2Index[e];
            for (const auto index : endTimesIndexs)
            {
                const int &s = startTime[index];
                dp[e] = max(dp[e], profit[index] + dp[s]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};