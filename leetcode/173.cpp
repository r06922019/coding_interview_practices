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

enum class State {
    INVALID,
    TRAVERSING_LEFT,
    TRAVERSING_SELF,
    TRAVERSING_RIGHT
};

class Item {
public:
    TreeNode *node = nullptr;
    State state = State::INVALID;

    Item(TreeNode *_n, State _s) {
        node = _n;
        state = _s;
    }
};

class BSTIterator {
public:
    stack<Item> traverse_stack;

    void push_left_children(TreeNode* root) {
        TreeNode *cur = root;
        while(cur) {
            if(cur->left)
                traverse_stack.push({cur, State::TRAVERSING_LEFT});
            else
                traverse_stack.push({cur, State::TRAVERSING_SELF});
            cur = cur->left;
        }
    }

    BSTIterator(TreeNode* root) {
        push_left_children(root);
    }

    int next() {
        auto &top_item = traverse_stack.top();
        auto node = top_item.node;
        auto &state = top_item.state;
        assert(state == State::TRAVERSING_SELF);
        int top_val = node->val;
        if(node->right) {
            state = State::TRAVERSING_RIGHT;
            push_left_children(node->right);
        }
        else {
            // no right child, pop self
            traverse_stack.pop();
            // if is right child of parent, pop all of them
            while(traverse_stack.size() && traverse_stack.top().state == State::TRAVERSING_RIGHT)
                traverse_stack.pop();
            // must be left child of the top if there's one
            if(traverse_stack.size())
                traverse_stack.top().state = State::TRAVERSING_SELF;
        }
        return top_val;
    }

    bool hasNext() {
        return traverse_stack.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */