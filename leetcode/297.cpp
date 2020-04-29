/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string DELIM = ",";
    // const char DELIM = ',';

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "null,";

        string ans = "";
        queue<TreeNode *> q;
        int non_null_count = 1;
        q.push(root);
        while(non_null_count) {
            non_null_count = 0;
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                TreeNode *cur = q.front();
                q.pop();
                if(cur == nullptr) {
                    ans += "null";
                }
                else {
                    ans += to_string(cur->val);
                    q.push(cur->left);
                    if(cur->left) {
                        ++non_null_count;
                    }
                    q.push(cur->right);
                    if(cur->right) {
                        ++non_null_count;
                    }
                }
                ans += DELIM;
            }
        }
        return ans.substr(0, ans.size());
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << endl;
        TreeNode *root = nullptr;
        if(data.find(',') == string::npos) return root;
        if(data == "null,") return root;

        int index = 0;
        root = parse_one_node(data, index);
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                TreeNode *cur = q.front();
                q.pop();
                cur->left = parse_one_node(data, index);
                if(cur->left) {
                    q.push(cur->left);
                }
                cur->right = parse_one_node(data, index);
                if(cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return root;
    }

    TreeNode *parse_one_node(string &data, int &index) {
        if(index >= data.size()) return nullptr;
        int new_index = data.find(',', index);
        string cur = data.substr(index, new_index-index);
        TreeNode *new_node = nullptr;
        if(cur != "null") {
            new_node = new TreeNode(stoi(cur));
        }

        index = new_index + 1;
        return new_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));