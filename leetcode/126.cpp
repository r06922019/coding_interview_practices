class Solution
{
public:
    vector<vector<int> > bfs(const int n, const int start, const int target, unordered_map<int, vector<int> > &adj_list)
    {
        vector<vector<int> > ret;
        int steps = 0;
        queue<pair<int, vector<int> > > q;
        bool not_found = true;
        vector<int> visited(n, -1);

        q.push({start, {start}});
        visited[start] = steps + 1;
        while (q.size() && not_found)
        {
            int q_size = q.size();
            while (q_size--)
            {
                pair<int, vector<int> > cur_pair = q.front();
                int cur = cur_pair.first;
                vector<int> path = cur_pair.second;
                q.pop();
                if (cur == target)
                {
                    not_found = false;
                    ret.push_back(path);
                }
                else
                {
                    for (auto neighbor : adj_list[cur])
                    {
                        if (visited[neighbor] == -1 || visited[neighbor] == steps + 1)
                        {
                            path.push_back(neighbor);
                            q.push({neighbor, path});
                            path.pop_back();
                            visited[neighbor] = steps + 1;
                        }
                    }
                }
            }
            ++steps;
        }

        return ret;
    }

    vector<vector<string> > findLadders(string begin_word, string end_word, vector<string> &word_list)
    {
        int n = word_list.size();
        unordered_map<string, int> word_set;
        for (int i = 0; i < n; ++i)
        {
            word_set[word_list[i]] = i;
        }

        if (word_set.find(begin_word) == word_set.end())
        {
            word_set[begin_word] = n;
            word_list.push_back(begin_word);
            n = word_list.size();
        }

        if (word_set.find(end_word) == word_set.end())
            return {};

        unordered_map<int, vector<int> > adj_list;
        for (int i = 0; i < n; ++i)
        {
            auto word = word_list[i];
            for (int j = 0; j < word.size(); ++j)
            {
                char original_char = word[j];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == original_char)
                        continue;
                    word[j] = c;
                    auto it = word_set.find(word);
                    if (it != word_set.end())
                    {
                        adj_list[i].push_back(it->second);
                    }
                }
                word[j] = original_char;
            }
        }

        vector<vector<int> > result = bfs(n, word_set[begin_word], word_set[end_word], adj_list);
        if (result.size() == 0)
            return {};
        vector<vector<string> > ans;
        for (auto indexs : result)
        {
            vector<string> vec;
            for (auto index : indexs)
            {
                vec.push_back(word_list[index]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};