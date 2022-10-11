class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int score = 0, max_score = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1;
        while (l <= r)
        {
            if (power >= tokens[l])
            {
                power -= tokens[l];
                ++l;
                ++score;
                max_score = max(max_score, score);
            }
            else if (score >= 1)
            {
                power += tokens[r];
                --r;
                --score;
            }
            else
            {
                break;
            }
        }
        return max_score;
    }
};