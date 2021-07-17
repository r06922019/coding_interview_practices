string simplifyPath(string path) {
    int index = 0;
    path += "/";
    vector<string> dir_names;
    string cur_name = "";
    while(index < path.size()) {
        auto &cur_char = path[index];
        if(isalpha(cur_char) || cur_char == '.') {
            cur_name += cur_char;
        }
        else if(cur_char == '/') {
            if(cur_name == "..") {
                if(dir_names.size()) dir_names.pop_back();
            }
            else if(cur_name != ".") {
                if(cur_name.size()) dir_names.push_back(cur_name);
            }
            cur_name = "";
        }
        ++index;
    }
    string ans = "/";
    for(int i = 0; i < dir_names.size(); ++i) {
        ans += dir_names[i];
        if(i + 1 < dir_names.size()) ans += "/";
    }
    return ans;
}
