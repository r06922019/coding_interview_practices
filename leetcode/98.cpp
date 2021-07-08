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
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode *root, TreeNode* cur_min, TreeNode* cur_max) {
        if(root == nullptr) return true;
        if(cur_max && root->val >= cur_max->val) return false;
        if(cur_min && root->val <= cur_min->val) return false;
        return helper(root->left, cur_min, root) && helper(root->right, root, cur_max);
    }
};