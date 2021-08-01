class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> rightest_index;
        for(int i = 0; i < s.size(); ++i) {
            rightest_index[s[i]] = i;
        }

        vector<int> ans;
        int start_index = 0, target_index = 0;
        for(int i = 0; i < s.size(); ++i) {
            target_index = max(target_index, rightest_index[s[i]]);
            if(target_index == i) {
                ans.push_back(target_index-start_index+1);
                start_index = i+1;
            }
        }
        return ans;
    }
};