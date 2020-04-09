#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */


void inorder_traversal(vector<vector<int>> &indexes, int cur, vector<int> &buf) {
    if(cur == -1) return ;
    inorder_traversal(indexes, indexes[cur-1][0], buf);
    buf.push_back(cur);
    inorder_traversal(indexes, indexes[cur-1][1], buf);
    return ;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */

    vector<vector<int>> ans;
    for(int &k : queries) {
        int cur_depth = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            for(int i = 0, n = q.size(); i < n; ++i) {
                int cur = q.front();
                q.pop();
                if(cur_depth % k == 0) {
                    swap(indexes[cur-1][0], indexes[cur-1][1]);
                }
                for(int j = 0; j <= 1; ++j) {
                    if(indexes[cur-1][j] != -1) {
                        q.push(indexes[cur-1][j]);
                    }
                }
            }
            ++cur_depth;
        }

        // inorder traversal
        vector<int> buf;
        inorder_traversal(indexes, 1, buf);
        ans.push_back(buf);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
