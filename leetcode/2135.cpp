// sorted string set
class Solution {
public:
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> startWordSet;
        for(auto word : startWords) {
            sort(word.begin(), word.end());
            startWordSet.insert(word);
        }
        
        int ans = 0;
        for(auto word : targetWords) {
            sort(word.begin(), word.end());
            for(int i = 0; i < word.size(); ++i) {
                if(startWordSet.count(word.substr(0,i) + word.substr(i+1))) {
                    ++ans;
                    break;
                }
            }
        }
        
        return ans;
    }
};

// Vector Hash 
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