class Solution {
public:
    int minSwaps(string s) {
        int r = s.size()-1;
        int left_brackets = 0, cost = 0;
        for(int l = 0; l < r; ++l) {
            if(s[l] == ']' && left_brackets == 0) {
                while(l < r && s[r] != '[') --r;
                swap(s[l], s[r]);
                ++cost;
            }
            if(s[l] == ']') {
                --left_brackets;
            }
            else {
                ++left_brackets;
            }
        }
        return cost;
    }
};