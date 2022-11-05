class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int cur = 0, ans = 0, n = plantTime.size();
        vector<int> indexs(n, 0);
        for (int i = 0; i < n; ++i)
        {
            indexs[i] = i;
        }
        sort(indexs.begin(), indexs.end(), [&plantTime, &growTime](const int &a, const int &b)
             { return (growTime[a] > growTime[b] || (growTime[a] == growTime[b] && plantTime[a] < plantTime[b])); });

        for (auto x : indexs)
        {
            const int grow = growTime[x], plant = plantTime[x];
            cur += plant;
            ans = max(ans, cur + grow);
        }

        //         auto cmp = [&plantTime, &growTime](const int &a, const int &b) {
        //             return !(growTime[a] > growTime[b] || (growTime[a] == growTime[b] && plantTime[a] < plantTime[b]));
        //         };
        //         priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        //         for(int i = 0; i < plantTime.size(); ++i) {
        //             pq.push(i);
        //         }

        //         while(pq.size()) {
        //             auto x = pq.top();
        //             pq.pop();
        //             const int grow = growTime[x], plant = plantTime[x];
        //             cur += plant;
        //             ans = max(ans, cur+grow);
        //         }

        return ans;
    }
};