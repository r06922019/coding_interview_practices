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
    const string DELIM = ",";
    const string NULL_STR = "null";

    string node_to_string(TreeNode *node) {
        if(node == nullptr) return NULL_STR + DELIM;
        return std::to_string(node->val) + DELIM;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = node_to_string(root);
        if(root) {
            ret += serialize(root->left) + serialize(root->right);
        }
        return ret;
    }

    vector<string> tokenize(string &data) {
        string buf = "";
        vector<string> result;
        for(auto &c : data) {
            if(c == DELIM[0]) {
                result.push_back(buf);
                buf = "";
            }
            else {
                buf += c;
            }
        }
        return result;
    }

    TreeNode* token_to_node(string token) {
        if(token == NULL_STR) return nullptr;
        return new TreeNode(std::stoi(token));
    }

    TreeNode* helper(vector<string> &tokens, int &index) {
        TreeNode *root = token_to_node(tokens[index]);
        ++index;
        if(root) {
            root->left = helper(tokens, index);
            root->right = helper(tokens, index);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string> tokens = tokenize(data);
        int index = 0;
        return helper(tokens, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

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