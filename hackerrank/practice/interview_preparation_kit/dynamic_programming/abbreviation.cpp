// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    vector<vector<bool>> lcs(a.size()+1, vector<bool>(b.size()+1, false));
    lcs[0][0] = true;
    int i = 1;
    while(i <= a.size() && islower(a[i-1])) {
        lcs[i][0] = true;
        ++i;
    }
    for(int index_a = 0; index_a < a.size(); ++index_a) {
        cout << a[index_a] << ": ";
        for(int index_b = 0; index_b < b.size(); ++index_b) {
            if(toupper(a[index_a]) == b[index_b]) {
                lcs[index_a+1][index_b+1] = lcs[index_a+1][index_b+1] | lcs[index_a][index_b];
            }
            if(islower(a[index_a])) {
                lcs[index_a+1][index_b+1] = lcs[index_a+1][index_b+1] | lcs[index_a][index_b+1];
            }
            cout << lcs[index_a+1][index_b+1] << " ";
        }
        cout << endl;
    }
    return (lcs[a.size()][b.size()])? "YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
