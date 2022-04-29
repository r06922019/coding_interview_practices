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
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val <= high)
            root->right = trimBST(root->right, low, high);
        if (root->val >= low)
            root->left = trimBST(root->left, low, high);
        if (root->val < low)
            return root->right;
        if (root->val > high)
            return root->left;
        return root;
    }
};