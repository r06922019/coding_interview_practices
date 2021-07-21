//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

Tree<int> *delete_in_bst(Tree<int> *root, int &num) {
    if(root == nullptr) return nullptr;
    if(num < root->value) {
        root->left = delete_in_bst(root->left, num);
        return root;
    }
    else if(root->value < num) {
        root->right = delete_in_bst(root->right, num);
        return root;
    }
    else { // root->value == num
        if(root->left) {
            // find the rightmost node of root->left
            Tree<int> *cur = root->left, *prev = nullptr;
            while(cur->right) {
                prev = cur;
                cur = cur->right;
            }
            if(prev) {
                root->value = cur->value;
                prev->right = cur->left;
                delete cur;
                return root;
            }
            else { // no right child in left tree
                root->left->right = root->right;
                Tree<int> *new_root = root->left;
                delete root;
                return new_root;
            }
        }
        else {
            Tree<int> *new_root = root->right;
            delete root;
            return new_root;
        }
    }
}

Tree<int> * deleteFromBST(Tree<int> * t, vector<int> queries) {
    for(auto &q : queries) {
        t = delete_in_bst(t, q);
    }
    return t;
}
