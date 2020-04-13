//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

Tree<int> *get_rightmost(Tree<int> *root) {
    if(root == NULL) return NULL;
    Tree<int> *rightmost = get_rightmost(root->right);
    if(rightmost) return rightmost;
    return root;
}

Tree<int> *remove_node(Tree<int> *node) {
    if(node == NULL) return NULL;
    if(node->left) {
        // left subtree
        Tree<int> *rightmost = get_rightmost(node->left);
        node->value = rightmost->value;

        if(node->left->value == rightmost->value) {
            node->left = node->left->left;
        }
        else {
            // weird way = =
            Tree<int> *prev = node->left;
            Tree<int> *cur = prev->right;
            while(cur->value != rightmost->value) {
                prev = cur;
                cur = cur->right;
            }
            prev->right = cur->left;
        }
        return node;
    }
    Tree<int> *right = node->right;
    delete(node);
    return right;
}

Tree<int> *delete_in_tree(Tree<int> *root, int q) {
    if(root == NULL) return NULL;

    if(q < root->value) {
        root->left = delete_in_tree(root->left, q);
    }
    else if(root->value < q) {
        root->right = delete_in_tree(root->right, q);
    }
    else { // ==
        root = remove_node(root);
    }
    return root;
}

Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
    for(int &q : queries)
        t = delete_in_tree(t, q);
    return t;
}
