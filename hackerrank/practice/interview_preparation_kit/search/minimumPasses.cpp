// #include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> split_string(string);
long safe_add(long cur, long days, long m, long w) {
    long diff = LONG_MAX - cur;
    if(diff/days/m/w <= 1) {
        return LONG_MAX;
    }
    return cur + days * m * w;
}

long days_left(long m, long w, long cur, long n) {
    return max((long)ceil((double)(n - cur) / m / w), (long)1);
}

// Complete the minimumPasses function below.
long minimumPasses(long m, long w, long p, long n) {
    long days = 0, cur = 0;
    do {
        // printf("days %ld\n", days);
        // printf("m %ld, w %ld, cur %ld\n", m, w, cur);

        bool invested = cur < p;
        while(cur >= p) {
            long cur_days_left = days_left(m, w, cur, n);
            if(cur_days_left <= 1) {
                break; // finish this day
            }
            // printf("cur_days_left %ld cur %ld\n", cur_days_left, cur);

            long new_days_left_if_buy_m = days_left(m+1, w, cur-p, n);
            // printf("new_days_left_if_buy_m %ld\n", new_days_left_if_buy_m);
            long new_days_left_if_buy_w = days_left(m+1, w, cur-p, n);
            // printf("new_days_left_if_buy_w %ld\n", new_days_left_if_buy_w);
            if(w >= m && new_days_left_if_buy_m <= cur_days_left) {
                ++m;
                cur -= p;
                invested = true;
            }
            else if(m >= w && new_days_left_if_buy_w <= cur_days_left) {
                ++w;
                cur -= p;
                invested = true;
            }
            else {
                break;
            }
        }

        // skip to end or cur >= p
        // printf("after spending: m %ld, w %ld, cur %ld\n", m, w, cur);

        long days_to_add = days_left(m, w, cur, n);
        if(invested)
            days_to_add = min(days_to_add, days_left(m, w, cur, p));
        // printf("days_to_add %ld\n", days_to_add);
        // cur += days_to_add * m * w;
        cur = safe_add(cur, days_to_add, m, w);
        days += days_to_add;
        // printf("m %ld, w %ld, cur %ld\n\n", m, w, cur);
    }while(cur < n);
    // printf("days %ld\n", days);
    return days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    long m = stol(mwpn[0]);

    long w = stol(mwpn[1]);

    long p = stol(mwpn[2]);

    long n = stol(mwpn[3]);

    long result = minimumPasses(m, w, p, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
