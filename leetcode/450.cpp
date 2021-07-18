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
    TreeNode* merge_trees(TreeNode *a, TreeNode *b) {
        if(a == nullptr && b == nullptr) return nullptr;
        if(a != nullptr && b == nullptr) return a;
        if(a == nullptr && b != nullptr) return b;

        // always pick a as the root
        if(a->val < b->val) {
            a->right = merge_trees(a->right, b);
        }
        else {
            a->left = merge_trees(a->left, b);
        }
        return a;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else
            root = merge_trees(root->left, root->right);
        return root;
    }
};