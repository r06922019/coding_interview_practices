#include <bits/stdc++.h>

using namespace std;

// Complete the crosswordPuzzle function below.

vector<vector<int>> get_pos_and_len(vector<string> &crossword) {
    vector<vector<int>> ret; // len i j dir
    // search for j dir
    for(int i = 0; i < crossword.size(); ++i) {
        for(int j = 0; j < crossword[i].size(); ++j) {
            if(crossword[i][j] == '-') {
                if(j == 0 || (j > 0 && crossword[i][j-1] != '-')) {
                    ret.push_back({1, i, j, 1});
                }
                else
                    ++ret.back()[0];
            }
        }
    }
    // search for i dir
    for(int j = 0; j < crossword[0].size(); ++j) {
        for(int i = 0; i < crossword.size(); ++i) {
            if(crossword[i][j] == '-') {
                if(i == 0 || (i > 0 && crossword[i-1][j] != '-')) {
                    ret.push_back({1, i, j, 0});
                }
                else
                    ++ret.back()[0];
            }
        }
    }
    return ret;
}

vector<string> split_string(string string_to_split, char delim) {
    vector<string> ret;
    string_to_split += delim;
    int index = 0;
    while(index < string_to_split.size()) {
        int next_index = string_to_split.find(delim, index);
        ret.push_back(string_to_split.substr(index, next_index-index));
        index = next_index + 1;
    }
    return ret;
}

bool can_put_word(vector<string> &crossword, int len, int i_start, int j_start, int dir, string word) {
    if(dir == 0) { // dir i
        for(int i = 0; i < len; ++i) {
            if(crossword[i_start+i][j_start] != '-') {
                if(crossword[i_start+i][j_start] != word[i]) {
                    return false;
                }
            }
        }
    }
    else {
        for(int j = 0; j < len; ++j) {
            if(crossword[i_start][j_start+j] != '-') {
                if(crossword[i_start][j_start+j] != word[j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void put_word(vector<string> &crossword, int len, int i_start, int j_start, int dir, string word) {
    if(dir == 0) { // dir i
        for(int i = 0; i < len; ++i) {
            crossword[i_start+i][j_start] = word[i];
        }
    }
    else {
        for(int j = 0; j < len; ++j) {
            crossword[i_start][j_start+j] = word[j];
        }
    }
    return ;
}

void revert(vector<string> &crossword, int len, int i_start, int j_start, int dir) {
    if(dir == 0) { // dir i
        for(int i = 0; i < len; ++i) {
            crossword[i_start+i][j_start] = '-';
        }
    }
    else {
        for(int j = 0; j < len; ++j) {
            crossword[i_start][j_start+j] = '-';
        }
    }
    return ;
}

bool helper(vector<string> &crossword, vector<string> &words, vector<bool> &used, int words_left, vector<vector<int>> &pos_and_len) {
    if(words_left == 0) {
        return true;
    }

    for(auto &v : pos_and_len) {
        int len = v[0], i = v[1], j = v[2], dir = v[3];
        for(int w_i = 0; w_i < words.size(); ++w_i) {
            if(!used[w_i] && words[w_i].size() == len) {
                if(can_put_word(crossword, len, i, j, dir, words[w_i])) {
                    put_word(crossword, len, i, j, dir, words[w_i]);
                    used[w_i] = true;
                    bool trial_result = helper(crossword, words, used, words_left-1, pos_and_len);
                    if(trial_result) {
                        return true;
                    }
                    used[w_i] = false;
                    revert(crossword, len, i, j, dir);
                }
            }
        }
    }


    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words_to_parse) {
    // gather all starting positions & len
    vector<vector<int>> pos_and_len = get_pos_and_len(crossword);

    // words_array
    vector<string> words = split_string(words_to_parse, ';');
    vector<bool> used(words.size(), false);

    // enumerate
    helper(crossword, words, used, words.size(), pos_and_len);
    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
