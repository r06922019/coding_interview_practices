class Solution {
public:

    int longest_substring_with_j_unique_char_at_least_k_times(string &s, int j, int k) {
        int l = 0, n = s.size(), ans = 0, k_times_count = 0;
        unordered_map<char, int> counter;
        for(int r = 0; r < n; ++r) {
            while(counter.find(s[r]) == counter.end() && counter.size() >= j) {
                if(counter[s[l]] == k)
                    --k_times_count;
                --counter[s[l]];
                if(counter[s[l]] == 0) {
                    counter.erase(s[l]);
                }
                ++l;
            }
            ++counter[s[r]];
            if(counter[s[r]] == k)
                ++k_times_count;
            if(k_times_count == counter.size()) {
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }


    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int j = 1; j <= 26; ++j) {
            ans = max(ans, longest_substring_with_j_unique_char_at_least_k_times(s, j, k));
        }
        return ans;
    }
};