/*
// backtrack 

class Solution {
public:
    void helper(TreeNode* root, int &visited, int &ans) {
        if(root == nullptr) return;
        visited ^= 1 << root->val;
        if(root->left == nullptr && root->right == nullptr && (visited == 0 || (visited & (visited-1)) == 0)) ++ans;
        helper(root->left, visited, ans);
        helper(root->right, visited, ans);
        visited ^= 1 << root->val;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0, visited = 0;
        helper(root, visited, ans);
        return ans;
    }
};
*/
/*

class ToggleSet {
public:
    unordered_set<int> s;
    
    bool toggle(const int x) {
        if(s.find(x) != s.end()) {
            s.erase(x);
            return false;
        }
            s.insert(x);
        return true;
    }
    
    size_t size() {
        return s.size();
    }
    
};

class Solution {
public:
    void helper(TreeNode* root, ToggleSet &visited, int &ans) {
        if(root == nullptr) return;
            visited.toggle(root->val);
        if(root->left == nullptr && root->right == nullptr && visited.size() <= 1) ++ans;
        helper(root->left, visited, ans);
        helper(root->right, visited, ans);
                    visited.toggle(root->val);

    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        ToggleSet visited;
        helper(root, visited, ans);
        return ans;
    }
};

*/

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
        int ans = 0;
        helper(root, 0, ans);
        return ans;
    }

    void helper(TreeNode *root, int counts, int &ans) {
        if(root == nullptr) return ;

        counts ^= (1 << root->val);

        // is_leaf
        if(root->left == nullptr && root->right == nullptr) {
            if((counts & (counts - 1)) == 0) {
                ++ans;
            }
        }
        else {
            for(auto &p : {root->left, root->right}) {
                helper(p, counts, ans);
            }
        }
        return ;
    }

//     int pseudoPalindromicPaths (TreeNode* root) {
//         vector<int> counts(9+1, 0);
//         int ans = 0;
//         helper(root, counts, ans);
//         return ans;
//     }

//     void helper(TreeNode *root, vector<int> &counts, int &ans) {
//         if(root == nullptr) return ;

//         ++counts[root->val];

//         // is_leaf
//         if(root->left == nullptr && root->right == nullptr) {
//             int odd = 0;
//             for(int &c : counts) {
//                 if(c % 2 == 1) {
//                     ++odd;
//                 }
//             }
//             if(odd <= 1) {
//                 ++ans;
//             }
//         }
//         else {
//             for(auto &p : {root->left, root->right}) {
//                 helper(p, counts, ans);
//             }
//         }

//         --counts[root->val];
//         return ;
//     }
};