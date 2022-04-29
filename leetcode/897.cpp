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
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode();
        TreeNode *cur = dummy;
        solve(root, cur);
        return dummy->right;
    }

    void solve(TreeNode *root, TreeNode *&cur)
    {
        if (root == nullptr)
            return;
        solve(root->left, cur);
        cur->right = root;
        cur = cur->right;
        cur->left = nullptr;
        solve(root->right, cur);
    }
};