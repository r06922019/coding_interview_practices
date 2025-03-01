class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        const int n = original.size();
        int a = bounds[0][0], b = bounds[0][1];
        for (int i = 1; i < n; ++i) {
            const int diff = original[i] - original[i - 1];
            a = max(a + diff, bounds[i][0]);
            b = min(b + diff, bounds[i][1]);
        }
        return (b >= a) ? b - a + 1 : 0;
    }
};
