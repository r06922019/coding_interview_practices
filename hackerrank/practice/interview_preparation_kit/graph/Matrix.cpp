#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int find_group(vector<int> &groups, int a) {
    if(groups[a] == a) return a;
    int group = find_group(groups, groups[a]);
    groups[a] = group;
    return group;
}

void set_group(vector<int> &groups, int a, int new_group) {
    if(groups[a] == a) {
        groups[a] = new_group;
        return ;
    }
    set_group(groups, groups[a], new_group);
    groups[a] = new_group;
    return ;
}

void merge_group(vector<int> &groups, int a, int b) {
    int new_group = min(find_group(groups, a), find_group(groups, b));
    set_group(groups, a, new_group);
    set_group(groups, b, new_group);
    return;
}

// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    for(auto &road : roads) {
        reverse(road.begin(), road.end());
    }
    sort(roads.rbegin(), roads.rend());

    int n = roads.size() + 1;
    vector<int> num_machines_of_city(n, 0);
    for(int &c : machines)
        num_machines_of_city[c] = 1;

    vector<int> groups(n, 0);
    for(int i = 0; i < n; ++i) {
        groups[i] = i;
    }

    vector<int> cut;
    for(auto &road : roads) {
        int &road_cost = road[0], &city_a = road[1], &city_b = road[2];
        int total_machines = 0;
        total_machines += num_machines_of_city[find_group(groups, city_a)];
        total_machines += num_machines_of_city[find_group(groups, city_b)];
        if(total_machines < 2) { // merge 2 groups
            merge_group(groups, city_a, city_b);
            num_machines_of_city[find_group(groups, city_a)] = total_machines;
        }
        else {
            cut.push_back(road_cost);
        }
    }
    if(cut.size() > 0)
        return accumulate(cut.begin(), cut.end(), 0);
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        string line;
        getline(cin, line);
        // cout << "cur_line: " << line << endl;
        vector<string> tmp = split_string(line);
        bool input_fail = tmp.size() != 3;
        for (int j = 0; j < 3 && !input_fail; j++) {
            roads[i][j] = stoi(tmp[j]);
        }
        if(input_fail) {
            --i;
            // cout << "input_fail " << line << endl;
        }
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

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
