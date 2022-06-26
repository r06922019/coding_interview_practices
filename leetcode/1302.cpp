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
#define TN TreeNode
    int deepestLeavesSum(TreeNode *root)
    {
        int ans = 0;
        queue<TN *> q;
        q.push(root);
        while (q.size())
        {
            int q_n = q.size();
            int cur_ans = 0;
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                cur_ans += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans = cur_ans;
        }
        return ans;
    }
};