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