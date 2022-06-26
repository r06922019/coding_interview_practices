class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int> > &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        int l = 0, n = tiles.size();
        int ans = 0;
        vector<int> num_tiles = {0};
        for (auto tile : tiles)
        {
            num_tiles.push_back(num_tiles.back() + tile[1] - tile[0] + 1);
        }
        for (int r = 0; r < n; ++r)
        {
            while (l < r && tiles[l][1] <= tiles[r][1] - carpetLen)
                ++l;
            int tmp_ans = num_tiles[r + 1] - num_tiles[l + 1] + 1;
            tmp_ans += tiles[l][1] - max(tiles[l][0], tiles[r][1] - carpetLen + 1);
            ans = max(ans, tmp_ans);
            // printf("r = %d, ans = %d\n", r, ans);
        }
        return ans;
    }
};