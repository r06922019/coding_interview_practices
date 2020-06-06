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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(9+1, 0);
        int ans = 0;
        helper(root, counts, ans);
        return ans;
    }

    void helper(TreeNode *root, vector<int> &counts, int &ans) {
        if(root == nullptr) return ;

        ++counts[root->val];

        // is_leaf
        if(root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for(int &c : counts) {
                if(c % 2 == 1) {
                    ++odd;
                }
            }
            if(odd <= 1) {
                ++ans;
            }
        }
        else {
            for(auto &p : {root->left, root->right}) {
                helper(p, counts, ans);
            }
        }

        --counts[root->val];
        return ;
    }
};