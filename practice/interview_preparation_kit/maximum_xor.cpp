#include <bits/stdc++.h>

/*
// compile on local
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
*/

using namespace std;

vector<string> split_string(string);

vector<int> to_bits(int num) {
    vector<int> bits(32, 0);
    for(int i = 0; i < 32 && num; ++i) {
        bits[i] = num&1;
        num >>= 1;
    }
    return bits;
}

class Node {
public:
    int data = -1;
    Node *children[2] = {NULL, NULL};
};

void add_value(Node *root, int num) {
    vector<int> bits = to_bits(num);
    int index = 31;
    Node *cur = root;
    while(index >= 0) {
        if(cur->children[ bits[index] ] == NULL) {
            cur->children[ bits[index] ] = new Node();
        }
        cur = cur->children[ bits[index] ];
        --index;
    }
    cur->data = num;
    return ;
}

int query_value(Node *root, int num) {
    vector<int> bits = to_bits(num);
    int index = 31;
    Node *cur = root;
    while(index >= 0) {
        // printf("index %d\n", index);
        int want = bits[index]^1;
        if(cur->children[want]) {
            cur = cur->children[want];
            // printf("index %d going %d\n", index, want);
        }
        else {
            cur = cur->children[ bits[index] ];
            // printf("index %d going %d\n", index, bits[index]);
        }
        --index;
    }
    return cur->data^num;
}

vector<int> maxXor(vector<int> arr, vector<int> queries) {
    vector<int> ans;
    Node *root = new Node();
    for(int &num : arr) {
        add_value(root, num);
    }

    for(int &num : queries) {
        ans.push_back(query_value(root, num));
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
