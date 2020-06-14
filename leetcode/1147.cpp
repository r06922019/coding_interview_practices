class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.size();
        if(len <= 1) return len; // empty string or single char

        int half_len = len / 2;
        for(int prefix_len = 1; prefix_len <= half_len; ++prefix_len) {
            if(text.substr(0, prefix_len) == text.substr(len-prefix_len, prefix_len)) {
                return 2+longestDecomposition(text.substr(prefix_len, len - prefix_len * 2));
            }
        }
        return 1;
    }
};
