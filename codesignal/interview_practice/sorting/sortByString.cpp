string sortByString(string s, string t) {
    if(s.empty()) return s;
    unordered_map<char, int> order;
    for(int i = 0; i < t.size(); ++i) {
        order[t[i]] = i;
    }
    sort(s.begin(), s.end(), [&](const char &a, const char &b){
        return order[a] < order[b];
    });
    return s;
}
