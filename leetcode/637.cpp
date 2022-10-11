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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ret;
        queue<TreeNode *> qu;
        qu.push(root);
        while (qu.size())
        {
            int q_n = qu.size();
            ret.push_back(q_n);
            double total = 0;
            while (q_n--)
            {
                auto front = qu.front();
                qu.pop();
                total += front->val;
                for (auto next : {front->left, front->right})
                {
                    if (next)
                        qu.push(next);
                }
            }
            ret.back() = total / ret.back();
        }
        return ret;
    }
};