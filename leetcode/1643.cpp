class Solution {
public:
    int c_a_b(int a, int b) {
        int num = 1, div = 1;
        for(int i = 1; i <= b; ++i) {
            num *= a;
            --a;
            div *= i;
            if(num % div == 0) {
                num /= div;
                div = 1;
            }
        }
        return num;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int v_max = destination[0], h_max = destination[1];
        int total = v_max + h_max;
        string ans = "";
        for(int i = 0; i < total; ++i) {
            // V > H
            // so if we chose V, we will skip all string starting from H
            if(destination[0] == 0) {
                ans += "H";
                --destination[1];
            }
            else if(destination[1] == 0) {
                ans += "V";
                --destination[0];
            }
            else {
                int v_skip_count = c_a_b(destination[0]+destination[1]-1,
                                        destination[1]-1); // we chose one H, we have rest of the string to be c(total, H-1)
                if(v_skip_count >= k) {
                    // skip too much, so we have to choose H
                    ans += "H";
                    --destination[1];
                }
                else {
                    ans += "V";
                    --destination[0];
                    k -= v_skip_count;
                }
            }
        }
        return ans;
    }
};