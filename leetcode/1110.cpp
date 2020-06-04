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
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        helper(root, to_del, true, ans);
        return ans;
    }

    TreeNode * helper(TreeNode *root, unordered_set<int> &to_del, bool is_root, vector<TreeNode*> &ans) {
        if(root == nullptr) return nullptr;

        bool deleted = to_del.find(root->val) != to_del.end();
        if(!deleted && is_root) ans.push_back(root);

        root->left = helper(root->left, to_del, deleted, ans);
        root->right = helper(root->right, to_del, deleted, ans);

        return deleted? nullptr:root;
    }

//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         vector<TreeNode*> ans;
//         unordered_set<int> to_del(to_delete.begin(), to_delete.end());
//         root = helper(root, to_del, ans);
//         if(root) ans.push_back(root);
//         return ans;
//     }

//     TreeNode * helper(TreeNode *root, unordered_set<int> &to_del, vector<TreeNode*> &ans) {
//         if(root == nullptr) return nullptr;

//         root->left = helper(root->left, to_del, ans);
//         root->right = helper(root->right, to_del, ans);

//         if(to_del.find(root->val) != to_del.end()) {
//             for(auto &p : {root->left, root->right}) {
//                 if(p) ans.push_back(p);
//             }
//             return nullptr;
//         }

//         return root;
//     }

};