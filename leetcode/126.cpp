class Solution
{
public:
    void backtrack(vector<int> &cur_path, vector<vector<int> > &ret, unordered_map<int, vector<int> > &adj_list, int cur)
    {
        if (adj_list[cur].size() == 0)
        {
            ret.push_back(cur_path);
            return;
        }
        for (auto next : adj_list[cur])
        {
            cur_path.push_back(next);
            backtrack(cur_path, ret, adj_list, next);
            cur_path.pop_back();
        }
    }

    vector<vector<int> > bfs(const int n, const int start, const int target, unordered_map<int, vector<int> > &adj_list)
    {
        int steps = 0;
        queue<int> q;
        bool not_found = true;
        vector<int> visited(n, -1);
        unordered_map<int, vector<int> > node_to_parent;

        q.push(start);
        node_to_parent[start] = {};
        visited[start] = steps + 1;
        while (q.size() && not_found)
        {
            int q_size = q.size();
            while (q_size--)
            {
                int cur = q.front();
                q.pop();
                if (cur == target)
                {
                    not_found = false;
                }
                else
                {
                    for (auto neighbor : adj_list[cur])
                    {
                        if (visited[neighbor] == -1)
                        {
                            q.push(neighbor);
                            node_to_parent[neighbor].push_back(cur);
                            visited[neighbor] = steps + 1;
                        }
                        else if (visited[neighbor] == steps + 1)
                        {
                            node_to_parent[neighbor].push_back(cur);
                        }
                    }
                }
            }
            ++steps;
        }

        vector<vector<int> > ret;
        if (!not_found)
        {
            vector<int> cur_path = {target};
            backtrack(cur_path, ret, node_to_parent, target);
        }
        return ret;
    }

    unordered_map<string, int> make_w2i(const string &begin_word, const string &end_word, vector<string> &word_list)
    {
        int n = word_list.size();
        unordered_map<string, int> w2i;
        for (int i = 0; i < n; ++i)
        {
            w2i[word_list[i]] = i;
        }

        if (w2i.find(begin_word) == w2i.end())
        {
            w2i[begin_word] = n;
            word_list.push_back(begin_word);
            n = word_list.size();
        }
        return w2i;
    }

    vector<vector<string> > findLadders(string begin_word, string end_word, vector<string> &word_list)
    {
        auto w2i = make_w2i(begin_word, end_word, word_list);
        if (w2i.find(end_word) == w2i.end())
            return {};

        unordered_map<int, vector<int> > adj_list;
        for (auto p : w2i)
        {
            auto word = p.first;
            const auto &index = p.second;
            for (int i = 0; i < word.size(); ++i)
            {
                const auto original_char = word[i];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == original_char)
                        continue;
                    word[i] = c;
                    auto it = w2i.find(word);
                    if (it != w2i.end())
                    {
                        adj_list[index].push_back(w2i[word]);
                    }
                }
                word[i] = original_char;
            }
        }

        vector<vector<int> > result = bfs(w2i.size(), w2i[begin_word], w2i[end_word], adj_list);
        vector<vector<string> > ans;
        for (auto indexs : result)
        {
            vector<string> vec;
            for (auto index : indexs)
            {
                vec.push_back(word_list[index]);
            }
            ans.push_back(vector<string>(vec.rbegin(), vec.rend()));
        }
        return ans;
    }
};