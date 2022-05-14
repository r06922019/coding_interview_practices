class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> seen_index;
        int ans = -1;
        for (int i = 0, n = cards.size(); i < n; ++i)
        {
            auto &card = cards[i];
            if (seen_index.find(card) != seen_index.end())
            {
                int cur_ans = i - seen_index[card] + 1;
                if (ans == -1 || cur_ans < ans)
                {
                    ans = cur_ans;
                }
            }
            seen_index[card] = i;
        }
        return ans;
    }
};