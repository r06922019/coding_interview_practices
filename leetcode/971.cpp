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

    void helper(TreeNode *root, vector<int> &voyage, int &index, vector<int> &ans) {
        if(root == nullptr) return;
        // if(index >= voyage.size()) return ;
        if(root->val != voyage[index]) return ;
        ++index;
        if(root->left && root->left->val != voyage[index]) {
            swap(root->left, root->right);
            ans.push_back(root->val);
        }
        helper(root->left, voyage, index, ans);
        helper(root->right, voyage, index, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int index = 0;
        helper(root, voyage, index, ans);
        if(index < voyage.size()) return {-1};
        return ans;
    }
};