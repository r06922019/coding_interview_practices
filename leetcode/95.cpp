/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        return (p.first << 4) + p.second;
    }
};

typedef unordered_map<pair<int, int>, vector<TreeNode*>, PairHash> PAIR_HASHMAP_VEC;

class Solution {
public:

    TreeNode *clone_tree(TreeNode *root) {
        if(root == nullptr) return nullptr;
        TreeNode *new_root = new TreeNode(root->val);
        new_root->left = clone_tree(root->left);
        new_root->right = clone_tree(root->right);
        return new_root;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        PAIR_HASHMAP_VEC table;

        for(int i = 1; i <= n; ++i) {
            vector<TreeNode*> v;
            v.push_back(new TreeNode(i));
            table[{i,i}] = v;
        }

        return helper(table, 1, n);
    }

    vector<TreeNode*> helper(PAIR_HASHMAP_VEC &table, int start, int end) {
        if(table.find({start, end}) != table.end()) return table[{start, end}];

        vector<TreeNode *> cur;
        for(int root_val = start; root_val <= end; ++root_val) {

            // prepare left trees
            int left_end = root_val-1;
            vector<TreeNode *> left_trees = {nullptr};
            if(start <= left_end) {
                left_trees = helper(table, start, left_end);
            }

            // prepare right trees
            int right_start = root_val + 1;
            vector<TreeNode *> right_trees = {nullptr};
            if(right_start <= end) {
                right_trees = helper(table, right_start, end);
            }

            // product
            for(auto &left : left_trees) {
                for(auto &right : right_trees) {
                    TreeNode *cur_root = new TreeNode(root_val);
                    cur_root->left = clone_tree(left);
                    cur_root->right = clone_tree(right);
                    cur.push_back(cur_root);
                }
            }
        }
        table[{start, end}] = cur;
        return cur;
    }
};
