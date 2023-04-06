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
    bool isCompleteTree(TreeNode *root)
    {
        bool seen_null = false;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            auto q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                if (cur == nullptr)
                {
                    seen_null = true;
                    continue;
                }
                else if (seen_null)
                {
                    return false;
                }
                for (auto nex : {cur->left, cur->right})
                    q.push(nex);
            }
        }
        return true;
    }
};