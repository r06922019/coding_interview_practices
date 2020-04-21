class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string n_string = to_string(N);
        int d_size = D.size(), n_size = n_string.size();

        int ans = 0;
        if(n_size > 1) {
            if(d_size != 1)
                ans += (int)(pow(d_size, n_size) - d_size) / (d_size-1);
            else
                ans += n_size-1;
        }

        for(int n_i = 0; n_i < n_size; ++n_i) {
            int d_i = d_size-1;
            while(d_i >= 0 && D[d_i][0] > n_string[n_i])
                --d_i;
            if(d_i >= 0) {
                if(D[d_i][0] == n_string[n_i] && n_i < n_size - 1) {
                    ans += (d_i) * pow(d_size, n_size-n_i-1);
                }
                else {
                    ans += (d_i+1) * pow(d_size, n_size-n_i-1);
                    break;
                }
            }
            else { // no valid starting number
                break;
            }
        }

        return ans;
    }
};