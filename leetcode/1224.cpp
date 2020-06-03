class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freqs; // {x,freq} x occurs freq times
        unordered_map<int, int> freq_counts; // {freq, count} freq occurs count times
        int ans = 1, n = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            --freq_counts[freqs[num]];
            ++freqs[num];
            int count = freqs[num];
            ++freq_counts[count];

            // all element has count of `count`
            // -> can append next element (if possible) to remove
            if(count * freq_counts[count] == (i+1) && (i+1) < n)
                ans = max(ans, i+1+1);

            // 1*(c+1), (n-1)*c, 1 * (c-1) -> 1*(c+1), n*c
            if(count * freq_counts[count] + count + 1 == (i+1))
                ans = max(ans, i+1);

            // 1*(1), (n-1)*c, 1 * (c-1) -> 1*(1), n*c
            if(count * freq_counts[count] + 1 == (i+1))
                ans = max(ans, i+1);
        }
        return ans;
    }
};