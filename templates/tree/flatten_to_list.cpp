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
    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        if(root->left == nullptr && root->right == nullptr) return;
        if(root->left) {
            flatten(root->left);
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = nullptr;
            // find head of right
            while(root->right) {
                root = root->right;
            }
            root->right = right;
        }
        flatten(root->right);
    }
};