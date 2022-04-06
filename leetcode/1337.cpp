class Solution
{
public:
#define VI vector<int>

    int find_key(const VI &vec)
    {
        if (vec.back() == 1)
            return vec.size();
        int l = 0, r = vec.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (vec[mid] == 0)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
        // return accumulate(vec.begin(),vec.end(),0);
    }

    vector<int> kWeakestRows(vector<vector<int> > &mat, int k)
    {
        unordered_map<int, VI> buckets;
        for (int i = 0; i < mat.size(); ++i)
        {
            const auto &vec = mat[i];
            int key = find_key(vec);
            buckets[key].push_back(i);
        }

        VI ans;
        for (int i = 0; i <= 100 && ans.size() < k; ++i)
        {
            for (auto x : buckets[i])
            {
                if (ans.size() < k)
                    ans.push_back(x);
                else
                    break;
            }
        }

        return ans;
    }
};