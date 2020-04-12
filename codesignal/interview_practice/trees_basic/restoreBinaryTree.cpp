//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    unordered_map<int, int> value_to_inorder_index;
    for(int i = 0; i < inorder.size(); ++i)
        value_to_inorder_index[inorder[i]] = i;
    int cur_root_index = 0;
    return helper(inorder, 0, inorder.size()-1, value_to_inorder_index, preorder, cur_root_index);
}

Tree<int> *helper(vector<int> &inorder, int start, int end, unordered_map<int, int> &value_to_inorder_index, vector<int> &preorder, int &cur_index) {
    if(start > end) return NULL;
    Tree<int> *root = new Tree<int>(preorder[cur_index]);
    ++cur_index;

    // handle left
    root->left = helper(inorder, start, value_to_inorder_index[root->value]-1, value_to_inorder_index, preorder, cur_index);

    // handle right
    root->right = helper(inorder, value_to_inorder_index[root->value]+1, end, value_to_inorder_index, preorder, cur_index);

    return root;
}
