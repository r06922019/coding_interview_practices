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
class Solution {
public:
    unordered_map<TreeNode *, int> dp = {{nullptr, 0}};
    int rob(TreeNode* root) {
        if(dp.find(root) != dp.end())
            return dp[root];

        int children_sum = rob(root->left) + rob(root->right);
        int grand_children_sum = 0;
        for(auto &p : {root->left, root->right}) {
            if(p) {
                grand_children_sum += rob(p->left) + rob(p->right);
            }
        }
        int ans = max(grand_children_sum + root->val, children_sum);
        dp[root] = ans;
        return ans;
    }
};