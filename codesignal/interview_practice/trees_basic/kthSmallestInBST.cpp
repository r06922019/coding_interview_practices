//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

Tree<int>* helper(Tree<int> *t, int k, int &count) {
    if(t == NULL) return NULL;
    Tree<int> *ret = helper(t->left, k, count);
    if(ret) return ret;
    ++count;
    if(k == count) return t;
    ret = helper(t->right, k, count);
    if(ret) return ret;
    return NULL;
}

int kthSmallestInBST(Tree<int> * t, int k) {
    int count = 0;
    return helper(t, k, count)->value;
}
