class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
//         sort(words.begin(), words.end(), [](const string &a, const string &b) {
//             return a.size() < b.size() || (a.size() == b.size() && a < b);
//         });

        vector<int> counter(26, 0);
        for(char &c : licensePlate) {
            if(isalpha(c)) {
                int index = tolower(c) - 'a';
                ++counter[index];
            }
        }

        string ans = "";
        for(string &word : words) {
            if(can_contain(word, counter) && (ans.empty() || ans.size() > word.size())) {
                ans = word;
            }
        }

        return ans;
    }

    bool can_contain(string &word, vector<int> &counter) {
        vector<int> word_counter(26, 0);
        for(char &c : word) {
            int index = tolower(c) - 'a';
            ++word_counter[index];
        }
        for(int i = 0; i < 26; ++i) {
            if(counter[i] > word_counter[i])
                return false;
        }
        return true;
    }

};