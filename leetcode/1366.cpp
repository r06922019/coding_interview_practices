class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> results(26, vector<int>(n, 0));
        vector<bool> seen(26, false);
        for(string &vote : votes) {
            for(int i = 0; i < n; ++i) {
                char &c = vote[i];
                int index = c - 'A';
                seen[index] = true;
                ++results[index][i];
            }
        }
        vector<char> ans;
        for(int i = 0; i < 26; ++i) {
            if(seen[i]) {
                ans.push_back('A' + i);
            }
        }
        auto comp = [&results, &n](const char &a, const char &b) {
            for(int i = 0; i < n; ++i) {
                if(results[a-'A'][i] > results[b-'A'][i]) return true;
                if(results[a-'A'][i] < results[b-'A'][i]) return false;
            }
            return a < b;
        };
        sort(ans.begin(), ans.end(), comp);
        return string(ans.begin(), ans.end());
    }
};