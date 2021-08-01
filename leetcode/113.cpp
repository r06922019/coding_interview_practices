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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur_ans;
        vector<vector<int>> ans;
        helper(root, targetSum, cur_ans, ans);
        return ans;
    }

    void helper(TreeNode* root, int targetSum,
                vector<int> &cur_ans, vector<vector<int>> &ans) {
        if(root == nullptr) return;
        cur_ans.push_back(root->val);
        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr) {
            if(targetSum == 0) {
                ans.push_back(cur_ans);
            }
        }
        helper(root->left, targetSum, cur_ans, ans);
        helper(root->right, targetSum, cur_ans, ans);
        cur_ans.pop_back();
        return;
    }
};