class Solution
{
public:
    int diff(const string &a, const string &b)
    {
        if (a.size() != b.size())
            return -1;
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
                ++cnt;
        }
        return cnt;
    }
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<string, int> gene_to_index;
        for (auto g : bank)
        {
            if (gene_to_index.find(g) == gene_to_index.end())
            {
                int index = gene_to_index.size();
                gene_to_index[g] = index;
            }
        }

        if (gene_to_index.find(end) == gene_to_index.end())
            return -1;
        if (gene_to_index.find(start) == gene_to_index.end())
            gene_to_index[start] = -1;

        unordered_map<int, vector<int>> adj_list;
        bank.push_back(start);
        for (auto g1 : bank)
        {
            for (auto g2 : bank)
            {
                if (diff(g1, g2) == 1)
                {
                    adj_list[gene_to_index[g1]].push_back(gene_to_index[g2]);
                    adj_list[gene_to_index[g2]].push_back(gene_to_index[g1]);
                }
            }
        }

        int steps = 0;
        const int end_index = gene_to_index[end];
        queue<int> q;
        unordered_set<int> visited;
        q.push(gene_to_index[start]);
        visited.insert(gene_to_index[start]);
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto front = q.front();
                q.pop();
                if (front == end_index)
                {
                    return steps;
                }
                for (auto next : adj_list[front])
                {
                    if (visited.find(next) == visited.end())
                    {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};