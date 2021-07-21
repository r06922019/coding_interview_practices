class TrieNode {
public:
    int count = 0;
    TrieNode* children[2] = {nullptr, nullptr};
    TrieNode() {}
};

class Trie {
public:
    TrieNode *root = nullptr;

    Trie() {
        root = new TrieNode();
    }

    void insert(int &num) {
        TrieNode *cur = root;
        for(int i = 30; i >= 0; --i) {
            int cur_bit = ((1<<i) & num)? 1:0;
            if(cur->children[cur_bit] == nullptr) {
                cur->children[cur_bit] = new TrieNode();
            }
            cur = cur->children[cur_bit];
        }
        ++cur->count;
    }

    int search_for_max_xor(int &num) {
        int ans = 0;
        TrieNode *cur = root;
        for(int i = 30; i >= 0; --i) {
            int cur_bit = ((1<<i) & num)? 1:0;
            int cur_inv_bit = ((1<<i) & num)? 0:1;
            if(cur->children[cur_inv_bit]) {
                cur = cur->children[cur_inv_bit];
                ans |= (cur_inv_bit<<i);
            }
            else {
                cur = cur->children[cur_bit];
                ans |= (cur_bit<<i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &num : nums) {
            trie.insert(num);
        }
        int ans = INT_MIN;
        for(auto &num : nums) {
            int x = trie.search_for_max_xor(num);
            ans = max(ans, x ^ num);
        }
        return ans;
    }
};