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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        vector<TreeNode*> to_find = {p, q};
        nodes_found(root, to_find, ans);
        return ans;
    }

    int nodes_found(TreeNode *root, vector<TreeNode*> &to_find, TreeNode *&ans) {
        if(root == nullptr) return 0;

        int cnt = 0;
        cnt += nodes_found(root->left, to_find, ans);
        cnt += nodes_found(root->right, to_find, ans);

        for(TreeNode* &n : to_find) {
            if(root->val == n->val) {
                ++cnt;
            }
        }

        if(cnt == to_find.size() && ans == nullptr) {
            ans = root;
        }
        // printf("%d cnt = %d\n", root->val, cnt);
        return cnt;
    }

};