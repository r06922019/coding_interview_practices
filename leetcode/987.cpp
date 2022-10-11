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
class Solution
{
public:
    void traverse(TreeNode *root, int level, int coord, map<int, map<int, vector<int>>> &data)
    {
        if (root == nullptr)
            return;
        data[coord][level].push_back(root->val);
        traverse(root->left, level + 1, coord - 1, data);
        traverse(root->right, level + 1, coord + 1, data);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> data;
        traverse(root, 0, 0, data);
        vector<vector<int>> ans;
        for (auto it : data)
        {
            auto cur_vertical_data = it.second;
            vector<int> cur_ans;
            for (auto vert : cur_vertical_data)
            {
                auto cur_level_data = vert.second;
                sort(cur_level_data.begin(), cur_level_data.end());
                for (auto x : cur_level_data)
                {
                    cur_ans.push_back(x);
                }
            }
            ans.push_back(cur_ans);
        }
        return ans;
    }
};