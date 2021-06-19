class Item {
public:
    struct Node *node;
    int state;
    // int state: -1 -> traversing left node, 1 -> traversing right node

    Item(struct Node *_node, int _s) {
        node = _node;
        state = _s;
    }
};

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum

    void push_left_children(struct Node *cur_node, stack<Item> &s) {
        while(cur_node) {
            if(cur_node->left)
                s.push({cur_node, -1});
            else
                s.push({cur_node, 0});
            cur_node = cur_node->left;
        }
    }

    void push_right_children(struct Node *cur_node, stack<Item> &s) {
        while(cur_node) {
            if(cur_node->right)
                s.push({cur_node, 1});
            else
                s.push({cur_node, 0});
            cur_node = cur_node->right;
        }
    }


    int isPairPresent(struct Node *root, int target)
    {
        stack<Item> min_stack, max_stack;

        // init min_stack
        push_left_children(root, min_stack);

        // init max_stack
        push_right_children(root, max_stack);

        while(min_stack.size() && max_stack.size()) {
            Item left_item = min_stack.top();
            Item right_item = max_stack.top();
            if(left_item.node == right_item.node) break;
            int cur_sum = left_item.node->data + right_item.node->data;
            if(cur_sum == target) {
                return 1;
            }
            else if(cur_sum < target) {
                // move left
                assert(left_item.state != -1);
                min_stack.pop();
                if(left_item.state == 0 && left_item.node->right) {
                    left_item.state = 1;
                    push_left_children(left_item.node->right, min_stack);
                }
                else {
                    if(min_stack.size()) {
                        min_stack.top().state = 0;
                    }
                }
            }
            else {
                // >
                // move right
                assert(right_item.state != 1);
                max_stack.pop();
                if(right_item.state == 0 && right_item.node->left) {
                    right_item.state = -1;
                    push_right_children(right_item.node->left, max_stack);
                }
                else {
                    if(max_stack.size()) {
                        max_stack.top().state = 0;
                    }
                }
            }
        }
        return 0;
    }
};