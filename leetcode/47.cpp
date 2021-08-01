class VecHash {
public:
    size_t operator()(const vector<int> &vec) const {
        int x = 0;
        for(auto num : vec) {
            x ^= num;
        }
        return (size_t)x;
    }
};

typedef unordered_set<vector<int>, VecHash> VECTOR_SET;

class Solution {
public:

    void helper(vector<int> &nums,
                vector<int> &buf,
                vector<bool> &used,
                VECTOR_SET &ans_set) {

        if(buf.size() == nums.size()) {
            ans_set.insert(buf);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(!used[i]) {
                used[i] = true;
                buf.push_back(nums[i]);
                helper(nums, buf, used, ans_set);
                used[i] = false;
                buf.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> buf;
        vector<bool> used(nums.size(), false);
        VECTOR_SET ans_set;
        helper(nums, buf, used, ans_set);

        vector<vector<int>> ans;
        for(auto &v : ans_set) {
            ans.push_back(v);
        }
        return ans;
    }
};