class Node {
public:
    int ends = 0;
    Node *children[52];
    int count = 0;

    Node() {
        for(int i = 0; i < 52; ++i)
            children[i] = NULL;
    }

};

int char_to_index(char c) {
    if(isupper(c)) {
        return 26 + c - 'A';
    }
    return c - 'a';
}

void insert(Node *cur, string s) {
    ++cur->count;
    for(int i = 0; i < s.size(); ++i) {
        int index = char_to_index(s[i]);
        if(cur->children[index] == NULL) {
            cur->children[index] = new Node();
        }
        cur = cur->children[index];
        ++cur->count;
    }
    ++cur->ends;
    return ;
}

bool query(Node *cur, string s) {
    for(int i = 0; i < s.size(); ++i) {
        int index = char_to_index(s[i]);
        if(cur->children[index] == NULL || cur->children[index]->count == 0) {
            return false;
        }
        cur = cur->children[index];
    }
    return cur->ends > 0;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    vector<string> ans;

    Node *root = new Node();
    for(auto &p : parts) {
        insert(root, p);
    }

    for(auto &word : words) {
        int max_index = -1, max_len = 0;
        // try each index
        for(int i = 0; i < word.size(); ++i) {
            int index = char_to_index(word[i]);
            if(root->children[index] != NULL) {
                for(int len = 1; len <= 5 && i+len <= word.size(); ++len) {
                    if(query(root, word.substr(i, len))) {
                        if(len > max_len) {
                            max_len = len;
                            max_index = i;
                        }
                    }
                }
            }
        }
        // construct new string
        if(max_len > 0) {
            string new_word = (max_index == 0)? "" : word.substr(0, max_index);
            new_word += "[" + word.substr(max_index, max_len) + "]";
            if(max_len < word.size())
                new_word += word.substr(max_index+max_len);
            ans.push_back(new_word);
        }
        else {
            ans.push_back(word);
        }
    }
    return ans;
}
