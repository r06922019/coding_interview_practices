//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if(t2 == NULL) return true;
    if(t1 == NULL) return false;
    return compare(t1, t2) || isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

bool compare(Tree<int> *t1, Tree<int> *t2) {
    if(t1 == NULL && t2 == NULL) return true;
    if(t1 == NULL || t2 == NULL) return false;
    if(t1->value != t2->value) return false;
    return compare(t1->left, t2->left) && compare(t1->right, t2->right);
}

