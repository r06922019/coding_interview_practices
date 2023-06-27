class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto x : nums)
        {
            pq.push(x);
        }
        int ans = 0;
        while (k--)
        {
            auto cur = pq.top();
            pq.pop();
            ans += cur;
            pq.push(cur + 1);
        }
        return ans;
    }
};