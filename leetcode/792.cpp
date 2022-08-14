/*
class WordState {
public:
    int cur_index;
    string s;
    WordState (int _i, string _s) {
        s = _s;
        cur_index = _i;
    }

    char front() {
        if(!is_end()) return s[cur_index];
        return 0;
    }

    bool is_end() {
        return cur_index == s.size();
    }

    void inc() {
        ++cur_index;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, queue<WordState>> char_to_word_states;
        for(auto w : words) {
            char_to_word_states[w[0]].push(WordState(0, w));
        }

        int ans = 0;
        for(auto cur_char : s) {
            auto &q = char_to_word_states[cur_char];
            int q_n = q.size();
            while(q_n--) {
                auto cur = q.front();
                q.pop();
                cur.inc();
                if(cur.is_end()) ++ans;
                else char_to_word_states[cur.front()].push(cur);
            }
        }
        return ans;
    }
};
*/

class Solution
{
public:
#define char_to_index(x) (x - 'a')
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<queue<pair<int, int> > > char_to_word_states(26, queue<pair<int, int> >());
        for (int index = 0; index < words.size(); ++index)
        {
            auto start = words[index][0];
            char_to_word_states[char_to_index(start)].push(pair<int, int>(0, index));
        }

        int ans = 0;
        for (auto cur_char : s)
        {
            auto &q = char_to_word_states[char_to_index(cur_char)];
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                ++cur.first;
                const auto &cur_word = words[cur.second];
                if (cur.first == cur_word.size())
                    ++ans;
                else
                    char_to_word_states[char_to_index(cur_word[cur.first])].push(cur);
            }
        }
        return ans;
    }
};