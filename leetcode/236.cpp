/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, TreeNode *&ans, unordered_set<TreeNode *> &to_find) {
        if(root == nullptr) return 0;
        int count = helper(root->left, ans, to_find) + helper(root->right, ans, to_find);
        if(to_find.find(root) != to_find.end()) {
            ++count;
        }
        if(count == 2 && ans == nullptr) {
            ans = root;
        }
        return count;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        unordered_set<TreeNode *> to_find;
        to_find.insert(p);
        to_find.insert(q);
        helper(root, ans, to_find);
        return ans;
    }
};