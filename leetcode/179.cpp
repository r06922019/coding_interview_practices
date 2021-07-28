class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto &num : nums) {
            vec.push_back(to_string(num));
        }

        sort(vec.begin(), vec.end(), [](const string &a, const string &b){
            return a+b > b+a;
        });

        string ans = "";
        for(auto &s : vec) {
            ans += s;
        }
        if(ans.front() == '0') return "0";
        return ans;
    }
};