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
    int maxLevelSum(TreeNode *root)
    {
        vector<int> level_sums;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int s = 0, q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                s += cur->val;
                for (auto n : {cur->left, cur->right})
                {
                    if (n)
                        q.push(n);
                }
            }
            level_sums.push_back(s);
        }
        return max_element(level_sums.begin(), level_sums.end()) - level_sums.begin() + 1;
    }
};