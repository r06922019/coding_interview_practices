class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int MOD = 1000000000+7;
        vector<int> us_A = unique_and_sort(A);
        unordered_map<int, int> counter_A = make_counter(A);
        int N = us_A.size();
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int &num_i = us_A[i];
            if( num_i * 3 == target) {
                if(counter_A[ num_i ] >= 3)
                    ans = (ans + C_n_get_k(counter_A[ num_i ], 3, MOD)) % MOD;
            }
            else if( num_i * 2 <= target) {
                if(counter_A[ num_i ] >= 2) {
                    int remainder = target - num_i * 2;
                    long long cur_cnt = C_n_get_k(counter_A[ num_i ], 2, MOD);
                    cur_cnt *= counter_A[remainder];
                    ans = (ans + (cur_cnt % MOD)) % MOD;
                }
            }

            // 1
            if(i < N-2) {
                int l = i+1, r = N-1;
                while(l < r) {
                    int cur_sum = us_A[i] + us_A[l] + us_A[r];
                    if(cur_sum == target) {
                        long long cur_cnt = 1;
                        cur_cnt = cur_cnt * counter_A[ us_A[i] ];
                        cur_cnt = cur_cnt * counter_A[ us_A[l] ];
                        cur_cnt = cur_cnt * counter_A[ us_A[r] ];
                        ans = (ans + (cur_cnt % MOD)) % MOD;
                    }

                    if(cur_sum > target) {
                        --r;
                    }
                    else {
                        ++l;
                    }
                }
            }
        }
        return ans;
    }

    vector<int> unique_and_sort(vector<int> &A) {
        set<int> set_a(A.begin(), A.end());
        return vector<int>(set_a.begin(), set_a.end());
    }

    unordered_map<int, int> make_counter(vector<int> &A) {
        unordered_map<int, int> counter_A;
        for(int &n : A) {
            ++counter_A[n];
        }
        return counter_A;
    }

    int C_n_get_k(int n, int k, int MOD) {
        if(k > n/2) k = n-k;
        long long ans = 1;
        for(int i = 1; i <= k; ++i) {
            if(ans % i == 0) {
                ans = ans / i;
                ans = ans * (n - i + 1);
            }
            else {
                ans = ans * (n - i + 1);
                ans = ans % MOD;
                ans = ans / i;
            }
            ans = ans % MOD;
        }
        return ans;
    }

};