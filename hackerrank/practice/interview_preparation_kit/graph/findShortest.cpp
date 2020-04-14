#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int start_bfs(int start_node_index, int n_nodes, unordered_map<int, vector<int>> &adj_list, vector<long> &colors) {

    queue<int> q;
    q.push(start_node_index);
    vector<bool> visited(n_nodes, false);
    visited[start_node_index] = true;
    int dis = 0;
    while(!q.empty()) {
        for(int i = 0, q_size = q.size(); i < q_size; ++i) {
            int front = q.front();
            q.pop();
            if(front != start_node_index && colors[front] == colors[start_node_index]) {
                return dis;
            }
            if(adj_list.find(front) != adj_list.end()) {
                for(int &child : adj_list[front]) {
                    if(!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
        ++dis;
    }
    return -1;
}


int findShortest(int n_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> colors, int val) {
    // start bfs from all id == val

    unordered_map<int, vector<int>> adj_list;
    for(int i = 0; i < graph_from.size(); ++i) {
        int &a = graph_from[i];
        int &b = graph_to[i];
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }


    /*
    // naive bfs
    int min_val = INT_MAX;
    for(int i = 0; i < colors.size(); ++i) {
        if(colors[i] == val) {
            int dis = start_bfs(i, n_nodes, adj_list, colors);
            if(dis > 0) {
                min_val = min(min_val, dis);
            }
        }
    }
    if(min_val == INT_MAX)
        return -1;
    return min_val;
    */

    // bfs @ all nodes with the color
    queue<pair<int, int>> q;
    vector<bool> visited(n_nodes, false);
    for(int i = 0; i < colors.size(); ++i) {
        if(colors[i] == val) {
            q.push({i, i});
        }
    }

    int dis = 0;
    while(!q.empty()) {
        for(int i = 0, q_size = q.size(); i < q_size; ++i) {
            pair<int, int> front_pair = q.front();
            q.pop();
            int start_node = front_pair.first;
            int cur_node = front_pair.second;
            visited[cur_node] = true;
            if(start_node != cur_node && colors[cur_node] == val) {
                return dis;
            }
            if(adj_list.find(cur_node) != adj_list.end()) {
                for(int &child : adj_list[cur_node]) {
                    if(colors[child] == val || !visited[child]) {
                        q.push({start_node, child});
                    }
                }
            }
        }
        ++dis;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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
