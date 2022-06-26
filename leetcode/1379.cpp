/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class State
{
public:
    TreeNode *original, *cloned, *target;

    State(TreeNode *_original, TreeNode *_cloned, TreeNode *_target)
    {
        original = _original;
        cloned = _cloned;
        target = _target;
    }

    vector<State> get_children()
    {
        vector<State> ret;
        if (original && cloned)
        {
            ret.push_back(move_left());
            ret.push_back(move_right());
        }
        return ret;
    }

    bool matched()
    {
        return original == target;
    }

private:
    State move_left()
    {
        return State(original->left, cloned->left, target);
    }

    State move_right()
    {
        return State(original->right, cloned->right, target);
    }
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        State root(original, cloned, target);
        queue<State> q;
        q.push(root);
        while (q.size())
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto front = q.front();
                q.pop();
                if (front.matched())
                    return front.cloned;
                for (auto child : front.get_children())
                {
                    q.push(child);
                }
            }
        }

        return nullptr;
    }
};