#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> plants) {
    stack<pair<int, int>> s;
    int max_day = 0;
    for(int &p : plants) {
        // pop them
        int days = 1;
        while(s.size() && s.top().first >= p) {
            days = max(days, s.top().second + 1);
            s.pop();
        }

        if(s.empty()) {
            s.push({p, 0});
        }
        else {
            s.push({p, days});
            max_day = max(max_day, days);
        }
    }
    return max_day;
    /*
    list<list<int>> list_of_list;
    list<int> cur_list;
    for(int &plant : plants) {
        // maintain each stack's decreasing order
        if(cur_list.size() > 0 && cur_list.back() < plant) {
            list_of_list.push_back(cur_list); // copies
            cur_list.clear();
        }
        cur_list.push_back(plant);
    }
    list_of_list.push_back(cur_list);
    int days = 0;
    while(list_of_list.size() > 1) {
        auto it = list_of_list.begin();
        ++it;
        for(; it != list_of_list.end(); ++it) {
            // remove each stacks (instead of first one) front
            it->pop_front();
        }
        it = list_of_list.begin();
        while(it != list_of_list.end()) {
            auto next_it = it;
            ++next_it;
            if(next_it == list_of_list.end()) break;
            if(next_it->empty()) { // if next empty
                list_of_list.erase(next_it);
            }
            else if(it->back() >= next_it->front()) { // if current tail >= next head
                it->splice(it->end(), *next_it); // merge in O(1)
                list_of_list.erase(next_it);
            }
            else {
                ++it;
            }
        }
        ++days;
    }
    return days;
    */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

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
