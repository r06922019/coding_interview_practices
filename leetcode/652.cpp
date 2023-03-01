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
    string traverse(TreeNode *root, unordered_map<string, vector<TreeNode *>> &trees)
    {
        if (root == nullptr)
            return "null";
        string cur = "(" + traverse(root->left, trees) + "|" + to_string(root->val) + "|" + traverse(root->right, trees) + ")";
        trees[cur].push_back(root);
        return cur;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, vector<TreeNode *>> trees;
        traverse(root, trees);
        vector<TreeNode *> ans;
        for (auto &p : trees)
        {
            auto &vec = p.second;
            if (vec.size() >= 2)
            {
                ans.push_back(vec.back());
            }
        }
        return ans;
    }
};