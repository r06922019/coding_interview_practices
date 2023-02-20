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
    void in_order(TreeNode *root, TreeNode *&prev, int &ans)
    {
        if (root == nullptr)
            return;
        if (root->left)
            in_order(root->left, prev, ans);
        if (prev)
            ans = min(ans, root->val - prev->val);
        prev = root;
        if (root->right)
            in_order(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX;
        TreeNode *prev = nullptr;
        in_order(root, prev, ans);
        return ans;
    }
};