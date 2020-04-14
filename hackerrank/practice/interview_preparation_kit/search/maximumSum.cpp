#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long m) {
    vector<long> acc(a.size()+1, 0);
    // compute prefix sum
    for(int i = 0; i < a.size(); ++i) {
        acc[i+1] = acc[i] + a[i];
    }
    // compute prefix sum mod
    for(long &num : acc) {
        num = num % m;
    }

    // construct {prefix_sum, sum_index} and sort
    vector<pair<long, int>> to_sort;
    for(int i = 0; i < acc.size(); ++i) {
        to_sort.push_back({acc[i], i});
    }
    sort(to_sort.begin(), to_sort.end());

    // sort for want minimum diff between prefix sums
    // (corresponds to maxmimum range sum due to mod)
    // compare neighbors, if i_a > i_b for:
    //              i-1 , i
    // prefix sum   a   , b
    // index        i_a , i_b
    // then range (i_a, i_b] has sum:
    // (a - b) % m => (-(b - a)) % m => m + a - b (b > a due to sort)
    long ans = *max_element(acc.begin(), acc.end());
    for(int i = 1; i < to_sort.size(); ++i) {
        if(to_sort[i-1].second > to_sort[i].second) {
            ans = max(ans, m + to_sort[i-1].first - to_sort[i].first);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

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
