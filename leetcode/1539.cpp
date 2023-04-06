class Solution
{
public:
    bool check(const int x, vector<int> &arr, const int k)
    {
        int l = 0, r = arr.size();
        while (l < r)
        {
            const int mid = l + (r - l) / 2;
            if (arr[mid] <= x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l + k <= x;
    }

    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 1, r = 2001;
        while (l < r)
        {
            const int mid = l + (r - l) / 2;
            if (check(mid, arr, k))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
    /* O(N)
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 1;
        for(auto x:arr){
            while(ans != x && k > 1) {
                --k;
                ++ans;
            }
            if(ans != x) break;
            ++ans;
        }
        while( k > 1) {
                --k;
                ++ans;
            }
        return ans;
    }
    */
};