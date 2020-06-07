class CodeGroup {
public:
    int code, count;
    CodeGroup() {
        code = count = 0;
    }
    CodeGroup(int _code, int _count) {
        code = _code;
        count = _count;
    }

};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();

        // counter
        unordered_map<int, int> counter;
        for(int &c : barcodes) {
            ++counter[c];
        }

        // sort w.r.t occurences
        vector<CodeGroup> code_groups;
        for(auto &it : counter) {
            const int &code = it.first, &count = it.second;
            code_groups.emplace_back(code, count);
        }

        // descending
        sort(code_groups.begin(), code_groups.end(), [](const CodeGroup &a, CodeGroup &b) {
            return a.count > b.count || (a.count == b.count && a.code > b.code);
        });

        // expand
        queue<int> sorted_with_count;
        for(auto &group : code_groups) {
            int code = group.code, count = group.count;
            while(count--) {
                sorted_with_count.push(code);
            }
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i += 2, sorted_with_count.pop()) {
            ans[i] = sorted_with_count.front();
        }
        for(int i = 1; i < n; i += 2, sorted_with_count.pop()) {
            ans[i] = sorted_with_count.front();
        }
        return ans;
    }
};