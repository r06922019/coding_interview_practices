class Solution {
public:
    int countTriplets(vector<int>& A) {
        // int cnt = 0, n = A.size();
        // brute-force
        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < n; ++j) {
        //         for(int k = 0; k < n; ++k) {
        //             if((A[i] & A[j] & A[k]) == 0) {
        //                 ++cnt;
        //             }
        //         }
        //     }
        // }
        // return cnt;

        // O( m * n * 2^16 ) dp
        int m = 3, n = A.size(), DP_SIZE = (1<<16);
        vector<int> table(DP_SIZE, 0);
        table.back() = 1; // base case
        for(int i = 0; i < m; ++i) {
            vector<int> new_table(DP_SIZE, 0);
            for(int j = 0; j < DP_SIZE; ++j) {
                if(table[j]) {
                    for(auto &num : A) {
                        new_table[num & j] += table[j];
                    }
                }
            }
            table = new_table;
        }
        return table[0];

        // O( min(n^2, 2^16) ) hashmap
        // int cnt = 0, n = A.size();
        // unordered_map<int, int> table;
        // for(auto &num1 : A) {
        //     for(auto &num2 : A) {
        //         ++table[ (num1 & num2) ];
        //     }
        // }
        // for(auto &num : A) {
        //     for(auto &it : table) {
        //         if((it.first & num) == 0) {
        //             cnt += it.second;
        //         }
        //     }
        // }
        // return cnt;

        // O( M * DP_SIZE * n ) dp (pick M numbers) -> TLE?
        // int DP_SIZE = 1 << 16, m = 3, cnt = 0, n = A.size();
        // vector<int> table(DP_SIZE, 0);
        // table.back() = 1;
        // for(int i = 1; i <= m; ++i) {
        //     vector<int> new_table(DP_SIZE, 0);
        //     for(auto &num : A) {
        //         for(int j = 0; j < DP_SIZE; ++j) {
        //             new_table[num & j] += table[j];
        //         }
        //     }
        //     table = new_table;
        // }
        // return table[0];

    }
};