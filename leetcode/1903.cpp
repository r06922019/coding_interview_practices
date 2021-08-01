class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() && !((num.back() - '0') & 1)) num.pop_back();
        return num;
    }
};