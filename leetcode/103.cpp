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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;
        while (q.size())
        {
            auto qn = q.size();
            vector<int> cur;
            while (qn--)
            {
                auto f = q.front();
                q.pop();
                cur.push_back(f->val);
                for (auto nex : {f->left, f->right})
                    if (nex)
                        q.push(nex);
            }
            ans.push_back(cur);
        }
        bool rev = false;
        for (auto &vec : ans)
        {
            if (rev)
                reverse(vec.begin(), vec.end());
            rev = !rev;
        }
        return ans;
    }
};