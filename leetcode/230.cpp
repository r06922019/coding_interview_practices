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
    void inorder(TreeNode *root, int k, int &cur, TreeNode *&ans)
    {
        if (root == nullptr)
            return;
        if (ans == nullptr)
            inorder(root->left, k, cur, ans);
        if (cur == k)
            ans = root;
        ++cur;
        if (ans == nullptr)
            inorder(root->right, k, cur, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int cur = 1;
        TreeNode *ans = nullptr;
        inorder(root, k, cur, ans);
        return ans->val;
    }
};