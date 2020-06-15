class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AxB;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B.size(); ++j) {
                ++AxB[A[i] + B[j]];
            }
        }

        int ans = 0;
        for(int k = 0; k < C.size(); ++k) {
            for(int l = 0; l < D.size(); ++l) {
                int target = 0 - (C[k] + D[l]);
                if(AxB.find(target) != AxB.end())
                    ans += AxB[target];
            }
        }
        return ans;
    }
};

// 454. 4Sum II
