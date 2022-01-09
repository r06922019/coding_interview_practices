class VectorHash
{
public:
    size_t operator()(const vector<int> vec) const
    {
        size_t x = 0;
        for (auto num : vec)
        {
            x = (x << 1) | (num & 1);
        }
        return x;
    }
};

class Solution
{
public:
    void str_to_vec(const string &s, vector<int> &vec)
    {
        fill(vec.begin(), vec.end(), 0);
        for (auto &c : s)
        {
            ++vec[c - 'a'];
        }
    }

    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        VectorHash hasher;
        unordered_map<vector<int>, int, VectorHash> counter;
        vector<int> vec(26, 0);
        for (auto word : startWords)
        {
            str_to_vec(word, vec);
            ++counter[vec];
        }

        int ans = 0;
        for (auto word : targetWords)
        {
            str_to_vec(word, vec);
            bool not_found = true;
            for (int i = 0; i < 26 && not_found; ++i)
            {
                if (vec[i])
                {
                    --vec[i];
                    if (counter.find(vec) != counter.end())
                    {
                        ++ans;
                        not_found = false;
                    }
                    ++vec[i];
                }
            }
        }

        return ans;
    }
};