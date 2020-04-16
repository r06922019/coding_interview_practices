#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool is_valid(vector<string> &grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
}


void go_to_end_or_x(vector<string> &grid, int i, int j, int d_i, int d_j, vector<vector<int>> &children) {
    while(is_valid(grid, i + d_i, j + d_j) && grid[i + d_i][j + d_j] != 'X') {
        i += d_i;
        j += d_j;
        children.push_back({i, j});
    }
    return ;
}

vector<vector<int>> span_children(vector<string> &grid, int i, int j) {
    vector<vector<int>> children;
    go_to_end_or_x(grid, i, j, -1, 0, children);
    go_to_end_or_x(grid, i, j, +1, 0, children);
    go_to_end_or_x(grid, i, j, 0, -1, children);
    go_to_end_or_x(grid, i, j, 0, +1, children);
    return children;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int start_i, int start_j, int end_i, int end_j) {
    int moves = 0;
    queue<vector<int>> q;
    q.push({start_i, start_j});
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    visited[start_i][start_j] = true;
    while(!q.empty()) {
        for(int q_i = 0, q_size = q.size(); q_i < q_size; ++q_i) {
            vector<int> cur_pair = q.front();
            q.pop();
            int &cur_i = cur_pair[0], &cur_j = cur_pair[1];
            if(cur_i == end_i && cur_j == end_j)
                return moves;
            // span 4-dir children
            vector<vector<int>> children = span_children(grid, cur_i, cur_j);
            for(auto &child : children) {
                int &child_i = child[0], &child_j = child[1];
                if(!visited[child_i][child_j]) {
                    q.push({child_i, child_j});
                    visited[child_i][child_j] = true;
                    // printf("move %d %d %d\n", moves, child_i, child_j);
                }
            }
        }
        ++moves;
    }
    return moves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
