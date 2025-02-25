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
#define PP pair<TreeNode *, int>
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<PP> q;
        q.push({root, 1});
        int ans = 1;

        while (q.size())
        {
            int q_n = q.size();
            long long int shift = 0;
            vector<PP> v;
            while (q_n--)
            {
                PP cur = q.front();
                q.pop();
                TreeNode *&node = cur.first;
                long long int pos = cur.second;

                if (node->left)
                {
                    if (v.empty())
                        shift = 2 * pos - 1;
                    v.push_back({node->left, 2 * pos - shift});
                }
                if (node->right)
                {
                    if (v.empty())
                        shift = 2 * pos;
                    v.push_back({node->right, 2 * pos + 1 - shift});
                }
            }

            if (v.size())
            {
                ans = max(ans, (int)(v.back().second - v.front().second + 1));
                for (auto p : v)
                {
                    q.push(p);
                }
            }
        }
        return ans;
    }
};