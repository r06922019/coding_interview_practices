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
    void solve(TreeNode *root, TreeNode *&prev, vector<TreeNode *> &nodes)
    {
        if (root == nullptr)
            return;

        solve(root->left, prev, nodes);
        int val = root->val;
        if (prev)
        {
            if (prev->val > val)
            {
                nodes.push_back(prev);
                nodes.push_back(root);
            }
        }
        prev = root;
        solve(root->right, prev, nodes);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        vector<TreeNode *> nodes;
        solve(root, prev, nodes);
        if (nodes.size() == 2)
            swap(nodes[0]->val, nodes[1]->val);
        else
            swap(nodes[0]->val, nodes[3]->val);
    }
};