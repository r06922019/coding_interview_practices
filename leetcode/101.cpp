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
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // return (root == nullptr) || helper(root->left, root->right);
        if (root == nullptr)
            return true;
        queue<TreeNode *> left, right;
        left.push(root->left);
        right.push(root->right);

        while (left.size() || right.size())
        {
            if (left.size() != right.size())
                return false;
            TreeNode *l = left.front();
            left.pop();
            TreeNode *r = right.front();
            right.pop();
            if (l == nullptr && r == nullptr)
                continue;
            if (l == nullptr || r == nullptr)
                return false;
            if (l->val != r->val)
                return false;
            left.push(l->left);
            left.push(l->right);
            right.push(r->right);
            right.push(r->left);
        }
        return true;
    }
};