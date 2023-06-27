class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        // O(nlogn)
        /*
        sort(arr.begin(), arr.end());
        for(int i = 2; i < arr.size(); ++i) {
            if(arr[i] - arr[i-1] != arr[1] - arr[0]) return false;
        }
        return true;
        */

        // O(n)
        const int min_val = *min_element(arr.begin(), arr.end());
        const int max_val = *max_element(arr.begin(), arr.end());
        const int diff = max_val - min_val, n = arr.size();
        if (diff % (n - 1) != 0)
            return false;
        const int step = diff / (n - 1);
        unordered_map<int, int> counter;
        for (int i = 0; i < n; ++i)
        {
            ++counter[min_val + step * i];
        }
        for (auto x : arr)
        {
            if (counter[x] <= 0)
                return false;
            --counter[x];
        }
        return true;
    }
};