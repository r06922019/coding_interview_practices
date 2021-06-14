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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        helper(root, 0, targetSum, ans, true);
        return ans;
    }

    void helper(TreeNode* root, long long int curSum,
                long long int targetSum, int &ans, bool is_start) {
        if(root == nullptr) return;
        curSum += root->val;
        if(curSum == targetSum) {
            ++ans;
        }
        for(auto &node : {root->left, root->right}) {
            helper(node, curSum, targetSum, ans, false);
            if(is_start)
                helper(node, 0, targetSum, ans, true);
        }
        return;
    }
};