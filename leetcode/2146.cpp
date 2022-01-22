class Item
{
public:
    int r, c, p, d;
    Item(int r_, int c_, int p_, int d_)
    {
        r = r_;
        c = c_;
        p = p_;
        d = d_;
    }
    bool operator==(const Item &other) const
    {
        return r == other.r && c == other.c && p == other.p && d == other.d;
    }

    bool operator>(const Item &other) const
    {
        /*
        Distance, defined as the length of the shortest path from the start (shorter distance has a higher rank).
        Price (lower price has a higher rank, but it must be in the price range).
        The row number (smaller row number has a higher rank).
        The column number (smaller column number has a higher rank).
        */
        if (d < other.d)
            return true;
        if (d == other.d && p < other.p)
            return true;
        if (d == other.d && p == other.p && r < other.r)
            return true;
        if (d == other.d && p == other.p && r == other.r && c < other.c)
            return true;
        return false;
    }

    bool operator>=(const Item &other) const
    {
        return (*this > other) || (*this == other);
    }

    bool operator<(const Item &other) const
    {
        return !(*this >= other);
    }
};

class Solution
{
public:
    inline bool is_valid(vector<vector<int> > &grid, int r, int c)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] > 0;
    }

    vector<vector<int> > highestRankedKItems(vector<vector<int> > &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        vector<vector<int> > diffs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
        };

        auto price_in_range = [&pricing](const int &p)
        {
            return p > 0 && p >= pricing[0] && p <= pricing[1];
        };

        vector<Item> items;
        queue<vector<int> > q;
        int steps = 0;

        q.push(start);
        if (price_in_range(grid[start[0]][start[1]]))
        {
            items.push_back(Item(start[0], start[1], grid[start[0]][start[1]], 0));
        }
        grid[start[0]][start[1]] = -1;

        while (q.size() && items.size() < k)
        {
            int n = q.size();
            // printf("dis %d\n", steps);
            while (n--)
            {
                auto cur = q.front();
                q.pop();
                int r = cur[0], c = cur[1];
                // printf("r = %d, c = %d\n", r, c);
                // branch neighbors
                for (auto diff : diffs)
                {
                    int new_r = r + diff[0];
                    int new_c = c + diff[1];
                    if (is_valid(grid, new_r, new_c))
                    {
                        // if price valid, put in pq
                        int new_p = grid[new_r][new_c];
                        if (price_in_range(new_p))
                        {
                            items.push_back(Item(new_r, new_c, new_p, steps + 1));
                        }
                        grid[new_r][new_c] = -1;
                        q.push({new_r, new_c});
                    }
                }
            }
            ++steps;
        }

        sort(items.rbegin(), items.rend());
        vector<vector<int> > ans;
        for (auto it : items)
        {
            ans.push_back({it.r, it.c});
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};