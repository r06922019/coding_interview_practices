/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        if (root)
            q.push(root);
        while (q.size())
        {
            int q_n = q.size();
            vector<int> cur_ans;
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                cur_ans.push_back(cur->val);
                for (auto child : cur->children)
                {
                    q.push(child);
                }
            }
            ans.push_back(cur_ans);
        }
        return ans;
    }
};