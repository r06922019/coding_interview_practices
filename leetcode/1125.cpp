class Solution
{
public:
    const long long ONE = (long long)1;
    unordered_map<string, int> make_skill_to_index(vector<string> &req_skills)
    {
        unordered_map<string, int> ans;
        for (auto x : req_skills)
        {
            if (ans.find(x) == ans.end())
            {
                ans[x] = ans.size();
            }
        }
        return ans;
    }

    vector<int> compress_people(unordered_map<string, int> &skill_to_index,
                                vector<vector<string>> &people)
    {
        vector<int> ans;
        for (auto person : people)
        {
            int result = 0;
            for (auto skill : person)
            {
                if (skill_to_index.find(skill) == skill_to_index.end())
                    continue;
                const int index = skill_to_index[skill];
                result |= 1 << index;
            }
            ans.push_back(result);
        }
        return ans;
    }

    vector<int> mask_to_array(const long long int &mask)
    {
        vector<int> arr;
        for (int i = 0; i < 60; ++i)
        {
            if (mask & (ONE << i))
            {
                arr.push_back(i);
            }
        }
        return arr;
    }

    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        unordered_map<string, int> skill_to_index = make_skill_to_index(req_skills);
        vector<int> compressed_people = compress_people(skill_to_index, people);

        const int n_skills = req_skills.size();
        const int n_people = compressed_people.size();
        const int want_skills = (1 << n_skills) - 1;
        vector<int> dp(want_skills + 1, n_people);
        vector<long long> masks(want_skills + 1, (ONE << n_people) - 1);
        dp[0] = masks[0] = 0;
        for (int i = 0; i < n_people; ++i)
        {
            const auto skill = compressed_people[i];
            for (int j = want_skills; j >= 0; --j)
            {
                int k = j | skill;
                if (k > j && dp[k] > dp[j] + 1)
                {
                    dp[k] = dp[j] + 1;
                    masks[k] = masks[j] | (ONE << i);
                }
            }
        }
        return mask_to_array(masks[want_skills]);
    }
};