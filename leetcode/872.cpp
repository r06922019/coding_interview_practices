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
    void gather(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            arr.push_back(root);
            return;
        }
        gather(root->left, arr);
        gather(root->right, arr);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<TreeNode *> leaves1, leaves2;
        gather(root1, leaves1);
        gather(root2, leaves2);
        if (leaves1.size() != leaves2.size())
            return false;
        for (int i = 0, n = leaves1.size(); i < n; ++i)
        {
            if (leaves1[i]->val != leaves2[i]->val)
                return false;
        }
        return true;
    }
};