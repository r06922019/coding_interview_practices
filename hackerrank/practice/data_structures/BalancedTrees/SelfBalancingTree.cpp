/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

void update_height(node *n) {
    if(n == nullptr) return ;
    int left = (n->left == nullptr)? -1:n->left->ht;
    int right = (n->right == nullptr)? -1:n->right->ht;
    n->ht = max(left, right) + 1;
    // printf("update %d height to %d\n", n->val, n->ht);
    return;
}


int get_balance(node *n) {
    if(n == nullptr) return 0;
    int left = (n->left == nullptr)? -1:n->left->ht;
    int right = (n->right == nullptr)? -1:n->right->ht;
    return left - right;
}


bool need_rotate(node *n) {
    if(n == nullptr) return false;
    int balance = get_balance(n);
    // printf("node %d balance factor = %d\n", n->val, balance);
    return balance > 1 || balance < -1;
}


bool left_heavy(node *n) {
    if(n == nullptr) return false;
    return get_balance(n) > 0;
}


node * case_left_left(node *n) {
    // printf("case_left_left\n");
    if(n == nullptr) return nullptr;
    node *new_root = n->left;
    n->left = new_root->right;
    update_height(n);
    new_root->right = n;
    update_height(new_root);
    return new_root;
}


node * case_left_right(node *n) {
    // printf("case_left_right\n");
    if(n == nullptr) return nullptr;
    node *left_child = n->left;
    node *left_right_child = left_child->right;

    left_child->right = left_right_child->left;
    update_height(left_child);
    left_right_child->left = left_child;
    update_height(left_right_child);
    n->left = left_right_child;
    update_height(n);

    return case_left_left(n);
}


node * case_right_right(node *n) {
    // printf("case_right_right\n");
    if(n == nullptr) return nullptr;
    node *new_root = n->right;
    n->right = new_root->left;
    update_height(n);
    new_root->left = n;
    update_height(new_root);
    return new_root;
}


node * case_right_left(node *n) {
    // printf("case_right_left\n");
    if(n == nullptr) return nullptr;
    node *right_child = n->right;
    node *right_left_child = right_child->left;

    right_child->left = right_left_child->right;
    update_height(right_child);
    right_left_child->right = right_child;
    update_height(right_left_child);
    n->right = right_left_child;
    update_height(n);

    return case_right_right(n);
}


node * rotate(node *n) {
    if(n == nullptr) return nullptr;
    // printf("rotating %d\n", n->val);
    if(left_heavy(n)) { // left heavy
        if(left_heavy(n->left)) {
            return case_left_left(n);
        }
        else {
            return case_left_right(n);
        }
    }
    else {
        if(left_heavy(n->right)) {
            return case_right_left(n);
        }
        else {
            return case_right_right(n);
        }
    }
    return nullptr;
}


node * insert(node * root, int val) {
    if(root == nullptr) {
        node *n = new node();
        n->val = val;
        n->left = n->right = nullptr;
        n->ht = 0;
        return n;
    }
    // printf("cur: %d\n", root->val);

    // insert
    if(val < root->val) {
        // printf("going left\n");
        root->left = insert(root->left, val);
    }
    else if(root->val < val) {
        // printf("going right\n");
        root->right = insert(root->right, val);
    }

    // rotate if needed
    if(need_rotate(root)) {
        root = rotate(root);
    }

    update_height(root);
    return root;
}