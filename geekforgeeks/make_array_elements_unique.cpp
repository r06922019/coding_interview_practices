class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        long long int ans = 0;
        sort(arr.begin(), arr.end());

        int prev = -1;
        for(auto x : arr) {
            if(x <= prev) {
                ans += prev - x + 1;
                prev = prev + 1;
            }
            else {
                prev = x;
            }
        }
        return ans;
    }
};