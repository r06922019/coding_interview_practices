class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int index_a = 0, index_b = 0;
        while(index_a < a.size() || index_b < b.size() || carry) {
            int cur = 0;
            if(index_a < a.size()) {
                cur += a[index_a] - '0';
                ++index_a;
            }
            if(index_b < b.size()) {
                cur += b[index_b] - '0';
                ++index_b;
            }
            cur += carry;
            ans.push_back((cur % 2) + '0');
            carry = cur / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};