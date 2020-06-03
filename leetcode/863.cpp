/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj_list;

        // bfs to build graph
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()) {
            TreeNode *cur = q.front();
            q.pop();
            int a = cur->val;
            for(TreeNode *p : {cur->left, cur->right}) {
                if(p) {
                    int b = p->val;
                    adj_list[a].push_back(b);
                    adj_list[b].push_back(a);
                    q.push(p);
                }
            }
        }

        return bfs_to_dis(target->val, adj_list, k);
    }

    vector<int> bfs_to_dis(int start, unordered_map<int, vector<int>> &adj_list, int dis) {
        vector<int> ret;

        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                int cur = q.front();
                q.pop();

                if(dis == 0) {
                    ret.push_back(cur);
                }
                else {
                    for(int &neigh : adj_list[cur]) {
                        if(visited.find(neigh) == visited.end()) {
                            visited.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            --dis;
        }

        return ret;
    }

};