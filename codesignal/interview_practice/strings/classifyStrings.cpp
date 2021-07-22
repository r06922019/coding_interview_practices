bool is_vowel(const char &c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool is_consonant(const char &c) {
    return isalpha(c) && !is_vowel(c);
}

bool is_bad(string s) {
    int vowels = 0, consonants = 0;
    for(auto &c : s) {
        if(is_vowel(c)) {
            ++vowels;
            consonants = 0;
        }
        else if(is_consonant(c)) {
            ++consonants;
            vowels = 0;
        }
        else {
            vowels = consonants = 0;
        }
        if(vowels == 3 || consonants == 5) return true;
    }
    return false;
}

string replace_q(const string &s, char new_char) {
    string ret = s;
    for(auto &c : ret) {
        if(c == '?') c = new_char;
    }
    return ret;
}

string greedily_be_good(const string &s) {
    string ret = s;
    int vowels = 0, consonants = 0;
    for(int i = 0; i < ret.size(); ++i) {
        auto &c = ret[i];
        if(c == '?') {
            if(vowels == 2) c = 'c';
            else if(consonants == 4) c = 'a';
            else {
                if(i+1 == ret.size() || is_vowel(ret[i+1]))
                    c = 'c';
                else
                    c = 'a';
            }
        }
        if(is_vowel(c)) {
            ++vowels;
            consonants = 0;
        }
        else { //if(is_consonant(c)) {
            ++consonants;
            vowels = 0;
        }
    }
    return ret;
}

string classifyStrings(string s) {
    if(is_bad(s)) return "bad";

    bool filled_vowels_is_bad = is_bad(replace_q(s, 'a'));
    bool filled_consonant_is_bad = is_bad(replace_q(s, 'b'));
    bool can_be_bad = filled_vowels_is_bad || filled_consonant_is_bad;
    bool can_be_good = !is_bad(greedily_be_good(s));
    if(!can_be_good && can_be_bad) return "bad";
    if(can_be_good && can_be_bad) return "mixed";
    // if(can_be_good && !can_be_bad)
    return "good";
}
