class Solution
{
public:
    int maxEnvelopes(vector<vector<int> > &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });

        vector<int> LIS;
        for (auto env : envelopes)
        {
            int x = env[1];
            int n = LIS.size();
            int index = 0;
            /* O(N)
            // O(N)
            for(; index < n; ++index) {
                if(!(x > LIS[index])) {
                    break;
                }
            }
            // O(N)
            */

            // O(logN)
            int l = 0, r = n;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (x <= LIS[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            index = l;
            // O(logN)

            if (index == n)
            {
                LIS.push_back(x);
            }
            else
            {
                LIS[index] = x;
            }
        }
        return LIS.size();
    }
};