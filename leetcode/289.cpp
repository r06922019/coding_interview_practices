class Solution
{
public:
    void mark_next_round_dead(vector<vector<int> > &board, int i, int j)
    {
        board[i][j] &= ~(0b10);
    }

    void mark_next_round_alive(vector<vector<int> > &board, int i, int j)
    {
        board[i][j] |= 0b10;
    }

    void proceed_to_next_round(vector<vector<int> > &board, int i, int j)
    {
        board[i][j] >>= 1;
    }

    bool is_currently_alive(vector<vector<int> > &board, int i, int j)
    {
        return board[i][j] & 1;
    }

    int count_living_neighbors(vector<vector<int> > &board, int i, int j, int m, int n)
    {
        int living_neighbors = 0;
        for (int di = -1; di <= 1; ++di)
        {
            for (int dj = -1; dj <= 1; ++dj)
            {
                if (di == 0 && dj == 0)
                    continue;
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    if (is_currently_alive(board, ni, nj))
                    {
                        ++living_neighbors;
                    }
                }
            }
        }
        return living_neighbors;
    }

    void gameOfLife(vector<vector<int> > &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int living_neighbors = count_living_neighbors(board, i, j, m, n);
                if (is_currently_alive(board, i, j))
                {
                    if (living_neighbors == 2 || living_neighbors == 3)
                    {
                        mark_next_round_alive(board, i, j);
                    }
                    else
                    {
                        mark_next_round_dead(board, i, j);
                    }
                }
                else // dead
                {
                    if (living_neighbors == 3)
                    {
                        mark_next_round_alive(board, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                proceed_to_next_round(board, i, j);
            }
        }
    }
};