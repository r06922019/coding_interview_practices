class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // vector<int> expected = heights;
        // sort(expected.begin(), expected.end());
        // int ans = 0;
        // for(int i = 0; i < heights.size(); ++i)
        //     if(heights[i] != expected[i])
        //         ++ans;
        // return ans;
        vector<int> counts(101, 0);
        for(auto &h : heights) {
            ++counts[h];
        }
        int ans = 0;
        for(int i = 0, j = 1; i < heights.size(); ++i) {
            while(counts[j] == 0) ++j;
            if(heights[i] != j) {
                ++ans;
            }
            --counts[j];
        }
        return ans;
    }
};