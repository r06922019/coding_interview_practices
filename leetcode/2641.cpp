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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        root->val = 0;
        while (q.size())
        {
            auto q_n = q.size();
            queue<TreeNode *> q1;
            int children_sum = 0;
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                q1.push(cur);
                for (auto x : {cur->left, cur->right})
                {
                    if (x)
                    {
                        q.push(x);
                        children_sum += x->val;
                    }
                }
            }

            auto q1_n = q1.size();
            while (q1_n--)
            {
                auto cur = q1.front();
                q1.pop();
                int cur_sum = 0;
                for (auto x : {cur->left, cur->right})
                {
                    if (x)
                    {
                        cur_sum += x->val;
                    }
                }
                for (auto x : {cur->left, cur->right})
                {
                    if (x)
                    {
                        x->val = children_sum - cur_sum;
                    }
                }
            }
        }
        return root;
    }
};