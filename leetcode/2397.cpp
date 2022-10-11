class Solution
{
public:
    int ones(int x)
    {
        int count = 0;
        while (x)
        {
            ++count;
            x = x & (x - 1); // abc100 -> abc011
        }
        return count;
    }

    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        vector<int> nums;
        int n = mat[0].size();
        for (auto &vec : mat)
        {
            int num = 0;
            for (int i = 0; i < n; ++i)
            {
                num |= (vec[i] << i);
            }
            nums.push_back(num);
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            if (ones(mask) != cols)
                continue;
            int tmp = 0;
            for (auto num : nums)
                if (((~mask) & num) == 0)
                    ++tmp;
            ans = max(tmp, ans);
        }
        return ans;
    }
};

/*
class Solution:
    def maximumRows(self, mat: List[List[int]], cols: int) -> int:
        m,n = len(mat), len(mat[0])
        self.ans = 0
        def helper(mask, cur_col):
            if len(mask) == n:
                tmp_ans = 0
                for row in mat:
                    matches = True
                    for i in range(n):
                        if mask[i] == 0 and row[i] == 1:
                            matches = False
                    if matches:
                        tmp_ans += 1
                self.ans = max(self.ans, tmp_ans)
                return

            if cur_col > 0:
                helper(mask + [1], cur_col-1)
            helper(mask + [0], cur_col)
            return

        helper([], cols)
        return self.ans
*/
