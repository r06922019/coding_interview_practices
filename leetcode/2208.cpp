class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> pq;
        double cur_sum = 0;
        for (auto num : nums)
        {
            cur_sum += num;
            pq.push(num);
        }

        int steps = 0;
        double new_sum = cur_sum, target = cur_sum / 2;
        while (new_sum > target)
        {
            auto top = pq.top();
            pq.pop();
            new_sum -= top / 2;
            pq.push(top / 2);
            ++steps;
        }
        return steps;
    }
};