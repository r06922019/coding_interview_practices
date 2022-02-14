class Solution
{
public:
    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<(1<<n);++i){ 
            bitset<10> mask(i);
            vector<int> vec;
            for(int j=0; j<n;++j)
                if(mask[j])
                    vec.push_back(nums[j]);
            ans.push_back(vec);
        }
return ans;
    }
*/

#define V vector
    void solve(V<int> &nums, const int i, const int n, V<int> &buf, V<V<int> > &ans)
    {
        if (i == n)
        {
            ans.push_back(buf);
            return;
        }

        solve(nums, i + 1, n, buf, ans);

        buf.push_back(nums[i]);
        solve(nums, i + 1, n, buf, ans);
        buf.pop_back();
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ans;
        vector<int> buf;
        solve(nums, 0, nums.size(), buf, ans);
        return ans;
    }
};