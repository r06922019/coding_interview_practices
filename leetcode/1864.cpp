class Solution {
public:
    int diff(string s, string target) {
        int wrong_at_zero = 0, wrong_at_one = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != target[i]) {
                if(s[i] == '0') {
                    ++wrong_at_zero;
                }
                else {
                    ++wrong_at_one;
                }
            }
        }
        if(wrong_at_zero == wrong_at_one) return wrong_at_zero;
        return -1;
    }

    int minSwaps(string s) {
        // try to adjust to 01010101
        string target01(s.size(), '0');
        for(int i = 1; i < target01.size(); i += 2)
            target01[i] = '1';

        int tmp01 = diff(s, target01);

        // try to adjust to 10101010
        string target10(s.size(), '0');
        for(int i = 0; i < target01.size(); i += 2)
            target10[i] = '1';

        int tmp10 = diff(s, target10);

        if(tmp01 >= 0 && tmp10 >= 0) {
            return min(tmp01, tmp10);
        }
        else if(tmp01 < 0 && tmp10 >= 0) {
            return tmp10;
        }
        else if(tmp01 >= 0 && tmp10 < 0) {
            return tmp01;
        }
        return -1;
    }
};