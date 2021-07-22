vector<string> textJustification(vector<string> words, int l) {
    vector<string> ans;
    int index = 0;
    while(index < words.size()) {
        vector<string> words_in_cur_line;
        int total_len = 0;
        while(index < words.size() &&
            (words_in_cur_line.empty() ||
                total_len + words_in_cur_line.size() + words[index].size() <= l)) {
            total_len += words[index].size();
            words_in_cur_line.push_back(words[index]);
            ++index;
        }

        // make the cur line
        string cur_line = "";
        if(index == words.size()) {
            // last line
            cur_line = words_in_cur_line[0];
            for(int i = 1; i < words_in_cur_line.size(); ++i) {
                cur_line += " " + words_in_cur_line[i];
            }
            while(cur_line.size() < l) cur_line += " ";
        }
        else if(words_in_cur_line.size() == 1) {
            // one word line
            cur_line = words_in_cur_line[0];
            while(cur_line.size() < l) cur_line += " ";
        }
        else {
            int num_spaces_needed = l - total_len;
            int space_base = num_spaces_needed / (words_in_cur_line.size()-1);
            int space_remaining = num_spaces_needed % (words_in_cur_line.size()-1);
            vector<int> space_counts(words_in_cur_line.size()-1, space_base);
            for(int i = 0; i < space_remaining; ++i) {
                ++space_counts[i];
            }
            cur_line = words_in_cur_line[0];
            for(int i = 1; i < words_in_cur_line.size(); ++i) {
                string spaces(space_counts[i-1], ' ');
                cur_line += spaces + words_in_cur_line[i];
            }
        }
        ans.push_back(cur_line);
    }
    return ans;
}
