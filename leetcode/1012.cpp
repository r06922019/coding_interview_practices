class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        if(N <= 10) return 0;
        vector<int> digits = get_digits(N);
        int count = N;

        // enumerate digits size < N size
        for(int i = 1; i < digits.size(); ++i) {
            int cur = 9; // first digit only 9 choices
            for(int j = 1; j < i; ++j) {
                cur *= (10-j);
            }
            count -= cur;
        }

        // enumerate digits size == N size but < N
        vector<bool> used(10, false);
        for(int i = 0; i < digits.size(); ++i) {
            int cur_count = 0;
            for(int j = (i==0)? 1:0; j < digits[i]; ++j) {
                if(!used[j]) {
                    ++cur_count;
                }
            }
            if(cur_count) {
                for(int j = i+1; j < digits.size(); ++j) {
                    cur_count *= (10-j);
                }
                count -= cur_count;
            }
            if(used[digits[i]]) break;
            used[digits[i]] = true;
        }

        // test if N is valid
        if(!is_valid(N))
            --count;

        return count;
    }

    bool is_valid(int num) {
        vector<int> count(10, 0);
        while(num) {
            int digit = num % 10;
            if(count[digit]) return true;
            ++count[digit];
            num /= 10;
        }
        return false;
    }

    vector<int> get_digits(int num) {
        string s = to_string(num);
        vector<int> ans(s.size(), 0);
        for(int i = 0; i < s.size(); ++i) {
            ans[i] = s[i] - '0';
        }
        return ans;
    }
};