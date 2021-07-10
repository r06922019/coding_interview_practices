class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<string, unordered_set<char>> data;
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for(auto &word : dictionary) {
            for(int i = 0; i < word.size(); ++i) {
                char cur_char = word[i];
                word[i] = '*';
                if(data.find(word) == data.end())
                    data[word] = unordered_set<char>();
                data[word].insert(cur_char);
                word[i] = cur_char;
            }
        }
    }

    bool search(string searchWord) {
        for(int i = 0; i < searchWord.size(); ++i) {
            char cur_char = searchWord[i];
            searchWord[i] = '*';
            if(data.find(searchWord) != data.end()) {
                auto &s = data[searchWord];
                if(s.find(cur_char) == s.end() || s.size() > 1)
                    return true;
            }
            searchWord[i] = cur_char;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */