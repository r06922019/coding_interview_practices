char DELIM = 12;

string next_token(string s, char delim, int &index) {
    if(index == s.size()) return "";
    int new_index = index;
    while(s[new_index] != delim)
        ++new_index;
    string ret = s.substr(index, new_index-index);
    index = new_index+1;
    return ret;
}

int determine_level(string &s, char target) {
    int index = 0;
    while(s[index] == target)
        ++index;
    return index;
}

int longestPath(std::string file_system) {
    int max_len = 0, index = 0, cur_stack_sum = 0;
    file_system += DELIM;
    stack<string> name_stack;
    while(index < file_system.size()) {
        string cur_name = next_token(file_system, DELIM, index);
        int level = determine_level(cur_name, '\t');
        cur_name = cur_name.substr(level);

        while(!name_stack.empty() && name_stack.size() > level) {
            cur_stack_sum -= name_stack.top().size();
            name_stack.pop();
        }

        if(cur_name.find('.') != string::npos) { // is file
            int cur_size = cur_stack_sum + cur_name.size() + name_stack.size();
            max_len = max(max_len, cur_size);
        }
        else {
            name_stack.push(cur_name);
            cur_stack_sum += cur_name.size();
        }
    }
    return max_len;
}



