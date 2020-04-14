#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    vector<int> counter(26, 0), skip(26, 0), need(26, 0);
    for(char &c : s)
        ++counter[c - 'a'];

    for(int i = 0; i < 26; ++i) {
        need[i] = skip[i] = counter[i] >> 1;
    }

    reverse(s.begin(), s.end());
    string ans = "";
    for(char &cur_char : s) {
        int cur_index = cur_char - 'a';
        if(need[cur_index] > 0) {
            if(ans.size() == 0) {
                ans += cur_char;
            }
            else {
                // pop those that can skip
                while(ans.size() && ans.back() > cur_char) {
                    int back_index = ans.back()-'a';
                    if(skip[back_index] > 0) {
                        --skip[back_index];
                        ++need[back_index];
                        ans.pop_back();
                    }
                    else {
                        break;
                    }
                }
                ans += cur_char;
            }
            --need[cur_index];
        }
        else{
            --skip[cur_index];
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
