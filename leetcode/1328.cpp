class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() <= 1) return "";

        string ans = "";
        for(int i = 0; i < palindrome.size(); ++i) {
            if(palindrome.size() % 2 == 1 && i == (palindrome.size()/2)) {
                continue;
            }
            char c = palindrome[i];
            if(c == 'a') {
                palindrome[i] = 'b';
            }
            else {
                palindrome[i] = 'a';
            }
            if(ans.empty() || ans > palindrome)
                ans = palindrome;
            palindrome[i] = c;
        }
        return ans;
    }
};