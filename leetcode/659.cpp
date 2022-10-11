class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, priority_queue<int> > tail_to_neg_lens;
        for (auto num : nums)
        {
            auto prev_len = 0;
            if (tail_to_neg_lens.find(num - 1) != tail_to_neg_lens.end())
            {
                auto &prev_pq = tail_to_neg_lens[num - 1];
                if (prev_pq.size())
                {
                    prev_len = prev_pq.top();
                    prev_pq.pop();
                }
            }
            tail_to_neg_lens[num].push(prev_len - 1);
        }
        for (auto p : tail_to_neg_lens)
        {
            auto pq = p.second;
            while (pq.size())
            {
                if (abs(pq.top()) < 3)
                    return false;
                pq.pop();
            }
        }
        return true;
    }
};