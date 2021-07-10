class Solution {
public:

    int reverse_in_row(int row, int label) {
        // each row has 2^r-1 elements, starting from 2^r-1
        int x = (1 << (row-1));
        return 3*x - 1 - label;
    }

    int get_row(int label) {
        int cur = 1, n = 0;
        while(cur <= label) {
            cur <<= 1;
            ++n;
        }
        return n;
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int row = get_row(label);
        if(row % 2 == 0) {
            label = reverse_in_row(row, label);
        }
        while(label) {
            ans.push_back(label);
            label >>= 1;
        }
        reverse(ans.begin(), ans.end());
        for(int i = 1; i <= row; ++i) {
            if(i % 2 == 0) {
                ans[i-1] = reverse_in_row(i, ans[i-1]);
            }
        }
        return ans;
    }
};