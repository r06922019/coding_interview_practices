class Solution{
public:
    const int MOD = 1e9+7;
    int add(const int &a, const int &b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    int mul(const int &a, const int &b) {
        long long tmp = a % MOD;
        tmp = tmp * (b % MOD);
        return (int)(tmp % MOD);
    }

    vector<vector<int>> mul_mat(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
        assert(mat1[0].size() == mat2.size());
        vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));

        for(int i = 0; i < mat1.size(); ++i) {
            for(int k = 0; k < mat2[0].size(); ++k) {
                for(int j = 0; j < mat2.size(); ++j) {
                    ans[i][k] = add(ans[i][k], mul(mat1[i][j], mat2[j][k]));
                }
            }
        }
        return ans;
    }

    vector<vector<int>> add_mat(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
        vector<vector<int>> ans = mat1;
        for(int i = 0; i < mat1.size(); ++i) {
            for(int j = 0; j < mat1[0].size(); ++j) {
                ans[i][j] = add(mat1[i][j], mat2[i][j]);
            }
        }
        return ans;
    }

    int countPaths(int N){
        if(N <= 1) return 0;
        vector<vector<int>> cur(4, vector<int>(1,0));
        cur[0][0] = 1;
        vector<vector<int>> mat = {
            {0,1,1,1},
            {1,0,1,1},
            {1,1,0,1},
            {1,1,1,0}
        };
        while(N) {
            if(N & 1) {
                cur = mul_mat(mat, cur);
            }
            N >>= 1;
            mat = mul_mat(mat, mat);
        }
        return cur[0][0];
    }
};