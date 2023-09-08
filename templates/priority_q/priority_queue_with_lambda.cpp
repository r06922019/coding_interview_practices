class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        auto comp = [](const int a, const int b)
        { return a > b; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp); // min pq uses greater comp
        for (auto &num : nums)
        {
            pq.push(num);
            while (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};