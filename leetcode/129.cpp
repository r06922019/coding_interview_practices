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
    int sumNumbers(TreeNode* root) {
        vector<int> cur_digits;
        int ans = 0;
        helper(root, cur_digits, ans);
        return ans;
    }

    void helper(TreeNode *root, vector<int> &cur_digits, int &ans) {
        if(root == nullptr) return;
        cur_digits.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            int tmp = 0;
            for(auto &digit : cur_digits) {
                tmp = tmp * 10 + digit;
            }
            ans += tmp;
        }
        for(auto &child : {root->left, root->right}) {
            helper(child, cur_digits, ans);
        }
        cur_digits.pop_back();
        return;
    }
};