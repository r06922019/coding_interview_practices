class Solution {
public:

    void append_digit(vector<int> &vec, int num, int diff) {
        int digit = num % 10;
        int new_digit = digit + diff;
        if(new_digit >= 0 && new_digit <= 9) {
            vec.push_back(num * 10 + new_digit);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans = {0,1,2,3,4,5,6,7,8,9};
        --N;
        while(N > 0) {
            vector<int> new_ans;
            for(int &num : ans) {
                if(num > 0) {
                    append_digit(new_ans, num, K);
                    if(K > 0)
                        append_digit(new_ans, num, -K);
                }
            }
            ans = new_ans;
            --N;
        }
        return ans;
    }
};
