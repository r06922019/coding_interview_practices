class Node {
public:
    int size, val;
    Node *left, *right;
    Node(int _v) {
        val = _v;
        size = 1;
        left = right = nullptr;
    }
};

class KthLargest {
public:
    Node *root;
    int k;

    void insert_num(int val) {
        if(root == nullptr) {
            root = new Node(val);
            return;
        }
        Node *cur = root;
        while(cur) {
            ++cur->size;
            if(val < cur->val) {
                if(cur->left) {
                    cur = cur->left;
                }
                else {
                    cur->left = new Node(val);
                    return;
                }
            }
            else {
                if(cur->right) {
                    cur = cur->right;
                }
                else {
                    cur->right = new Node(val);
                    return;
                }
            }
        }
    }

    KthLargest(int _k, vector<int>& nums) {
        k = _k;
        root = nullptr;
        for(auto &num : nums) {
            insert_num(num);
        }
    }

    int add(int val) {
        insert_num(val);
        Node *cur = root;
        int cur_k = k;
        assert(cur->size >= k);
        while(true) {
            int left_size = (cur->left)? cur->left->size:0;
            int right_size = (cur->right)? cur->right->size:0;
            if(right_size >= cur_k) {
                cur = cur->right;
            }
            else if(right_size + 1 == cur_k) {
                return cur->val;
            }
            else {
                cur_k -= right_size + 1;
                cur = cur->left;
            }
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */