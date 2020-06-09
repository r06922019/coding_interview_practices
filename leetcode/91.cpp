class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n+1, 0); // dp[i] -> ways to decode len i
        vector<vector<int>> prev(n+1, vector<int>()); // prev[i] -> inherited from i
        dp[0] = 1; //
        for(int i = 1; i <= n; ++i) {
            int cur_digit = s[i-1] - '0';
            if(cur_digit != 0) {
                dp[i] += dp[i-1];
                prev[i].push_back(i-1);
            }
            if(i - 2 >= 0) {
                int prev_digit = s[i-2] - '0';
                int num = prev_digit * 10 + cur_digit;
                if(num >= 10 && num <= 26) {
                    dp[i] += dp[i-2];
                    prev[i].push_back(i-2);
                }
            }
        }

        // print from prev
        // vector<string> possible_strings = get_possible_strings(s, prev);
        // for(auto &possible_string : possible_strings)
        //     cout << possible_string << endl;
        return dp[n];
    }

    vector<string> get_possible_strings(string &s, vector<vector<int>> &prev) {
        vector<string> possible_strings;
        string buf = "";
        back_track(s.size(), s, prev, buf, possible_strings);
        for(string &possible_string : possible_strings) {
            reverse(possible_string.begin(), possible_string.end());
        }
        reverse(possible_strings.begin(), possible_strings.end());
        return possible_strings;
    }

    void back_track(int index, string &s, vector<vector<int>> &prev, string &buf, vector<string> &possible_strings){
        if(index == 0) {
            possible_strings.push_back(buf);
            return ;
        }
        for(auto &prev_index : prev[index]) {
            int code = 0;
            for(int i = prev_index; i < index; ++i) {
                code = code * 10 + (s[i]-'0');
            }
            buf += code + 'A' - 1;
            back_track(prev_index, s, prev, buf, possible_strings);
            buf.pop_back();
        }
        return ;
    }
};
