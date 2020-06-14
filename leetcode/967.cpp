class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<string> str_ans = solve(N, K);
        vector<int> ans;
        for(string &s : str_ans) {
            reverse(s.begin(), s.end());
            if(s.size() && (N == 1 || (N > 1 && s[0] != '0')))
            ans.push_back(stoi(s));
        }
        return ans;
    }

    vector<string> solve(int N, int K) {
        if(N == 1) {
            vector<string> ret;
            for(int i = 0; i <= 9; ++i)
                ret.push_back(to_string(i));
            return ret;
        }

        // first solve N-1, K
        vector<string> ans;
        for(string &sub_ans : solve(N-1, K)) {
            int last_digit = sub_ans.back() - '0';
            vector<int> possibilities = {last_digit-K};
            if(K > 0) possibilities.push_back(last_digit+K);
            for(int new_digit : possibilities) {
                if(new_digit >= 0 && new_digit <= 9) {
                    ans.push_back(sub_ans + to_string(new_digit));
                }
            }
        }
        return ans;
    }
};
