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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            vector<int> cur_ans;
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                cur_ans.push_back(cur->val);
                for (auto next : {cur->left, cur->right})
                    if (next)
                        q.push(next);
            }
            ans.push_back(cur_ans);
        }

        return ans;
    }
};