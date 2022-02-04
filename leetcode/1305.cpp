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
    void flatten(TreeNode* root, vector<int> &vec) {
        if(root == nullptr) return;
        flatten(root->left, vec);
        vec.push_back(root->val);
        flatten(root->right, vec);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        flatten(root1, vec1);
        flatten(root2, vec2);
        
        vector<int> ans;
        while(vec1.size() || vec2.size()) {
            if(vec1.empty() || (vec2.size() && vec1.back() < vec2.back())) {
                ans.push_back(vec2.back());
                vec2.pop_back();
            }
            else {
                ans.push_back(vec1.back());
                vec1.pop_back();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};