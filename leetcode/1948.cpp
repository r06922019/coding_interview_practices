class Node {
public:
    int count = 0;
    map<string, Node *> children;
    Node(){}
};

class Tree {
public:
    Node *root = new Node();
    Tree(){}
    void insert(vector<string> &vec) {
        Node *cur = root;
        for(auto &s : vec) {
            if(cur->children.find(s) == cur->children.end()) {
                cur->children[s] = new Node();
            }
            cur = cur->children[s];
        }
        ++cur->count;
    }

    void trim() {
        unordered_map<string, Node *> path_to_parent;
        trim(root, path_to_parent);
    }

    string trim(Node *cur,
                    unordered_map<string, Node *> &path_to_parent) {
        // summarize cur node's children with a string
        // insert
        string summarization = "";
        for(auto &p : cur->children) {
            auto &name = p.first;
            auto &child = p.second;
            summarization += "|" + p.first + trim(child, path_to_parent);
        }
        if(summarization.size() > 0) {
            if(path_to_parent.find(summarization) != path_to_parent.end()) {
                cur->children.clear();
                --cur->count;
                path_to_parent[summarization]->children.clear();
                --path_to_parent[summarization]->count;
            }
            else {
                path_to_parent[summarization] = cur;
            }
        }
        summarization = "{" + summarization + "}";
        printf("%s\n", summarization.c_str());
        return summarization;
    }

    void traverse(vector<vector<string>> &ans) {
        vector<string> buf;
        traverse(root, buf, ans);
    }

    void traverse(Node *cur, vector<string> &buf, vector<vector<string>> &ans) {
        if(cur == nullptr) return ;
        if(buf.size() && cur->count > 0) {
            ans.push_back(buf);
        }
        for(auto &p : cur->children) {
            auto &s = p.first;
            auto &child = p.second;
            buf.push_back(s);
            traverse(child, buf, ans);
            buf.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Tree tree;
        for(auto &path : paths) {
            tree.insert(path);
        }
        tree.trim();

        vector<vector<string>> ans;
        tree.traverse(ans);
        return ans;
    }
};