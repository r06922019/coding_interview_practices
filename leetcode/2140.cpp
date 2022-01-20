class Solution
{
public:
    long long mostPoints(vector<vector<int> > &questions)
    {
        int n = questions.size();
        vector<long long> prev_score(n, 0);
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            // give up current question
            if (i + 1 < n)
            {
                prev_score[i + 1] = max(prev_score[i + 1], prev_score[i]);
            }

            // do current_question
            long long new_score = prev_score[i] + questions[i][0];
            int new_index = i + questions[i][1] + 1;
            ans = max(ans, new_score);
            if (new_index < n)
            {
                prev_score[new_index] = max(prev_score[new_index], new_score);
            }
        }
        return ans;
    }
};