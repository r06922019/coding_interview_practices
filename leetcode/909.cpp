class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        const bool debug = false;
        int n = board.size();
        vector<bool> visited(n * n, false);
        vector<int> shortcut(n * n, -1);

        for (int index = 0, i = n - 1, dir = 0; i >= 0; --i)
        {
            if (dir == 0)
            {
                for (int j = 0; j < n; ++j, ++index)
                {
                    shortcut[index] = (board[i][j] > 0) ? board[i][j] - 1 : -1;
                }
                dir = 1;
            }
            else
            { // dir == 1
                for (int j = n - 1; j >= 0; --j, ++index)
                {
                    shortcut[index] = (board[i][j] > 0) ? board[i][j] - 1 : -1;
                }
                dir = 0;
            }
        }

        const int end = n * n - 1;
        int steps = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (q.size())
        {
            int q_n = q.size();
            if (debug)
                printf("steps %d\n", steps);
            while (q_n--)
            {
                int cur = q.front();
                q.pop();
                if (debug)
                    printf("  cur %d\n", cur);
                if (cur == end)
                    return steps;
                // [curr + 1, min(curr + 6, n^2)]
                for (int d = 1; d <= 6 && cur + d <= end; ++d)
                {
                    int nex = cur + d;
                    if (shortcut[nex] != -1)
                    {
                        nex = shortcut[nex];
                    }
                    if (debug)
                        printf("    trying nex %d\n", nex);
                    if (!visited[nex])
                    {
                        if (debug)
                            printf("      pushing nex %d\n", nex);
                        q.push(nex);
                        visited[nex] = true;
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};