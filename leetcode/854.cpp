class Solution {
public:
    int kSimilarity(string A, string B) {
        int steps = 0, n = A.size();
        queue<string> q;
        unordered_set<string> visited;

        q.push(A);
        visited.insert(A);
        while(q.size()) {
            for(int q_i = 0, q_n = q.size(); q_i < q_n; ++q_i) {
                string cur = q.front();
                q.pop();
                if(cur == B) return steps;

                int index1 = -1;
                for(int i = 0; i < n; ++i) {
                    if(cur[i] != B[i]) {
                        if(index1 < 0) {
                            index1 = i;
                        }
                        else if(cur[i] == B[index1]){
                            string tmp = cur;
                            swap(tmp[i], tmp[index1]);
                            if(visited.find(tmp) == visited.end()) {
                                visited.insert(tmp);
                                q.push(tmp);
                            }
                        }
                    }
                }
            }
            ++steps;
        }
        return steps;
    }

    vector<int> compare_strings(string &a, string &b) {
        vector<int> ret;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }

};