class Solution
{
public:
    int bfs(const int n, const int start, const int target, unordered_map<int, vector<int> > &adj_list)
    {
        int steps = 0;
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;
        while (q.size())
        {
            int q_size = q.size();
            while (q_size--)
            {
                int cur = q.front();
                q.pop();
                if (cur == target)
                    return steps + 1;
                for (auto neighbor : adj_list[cur])
                {
                    if (!visited[neighbor])
                    {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            ++steps;
        }

        return 0;
    }
    int ladderLength(string begin_word, string end_word, vector<string> &word_list)
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
            return 0;

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

        return bfs(n, word_set[begin_word], word_set[end_word], adj_list);
    }
};