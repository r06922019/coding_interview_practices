class Solution{
private:
    // do not edit this function
    // use it to get the value of A[i][j]
    int get(int i,int j){
        return a.get(i,j);
    }
public:
    int solve(int R,int C){
        int cur_r = 0, cur_c = C-1, ans = 0;
        while(cur_r < R && cur_c >= 0) {
            if(a.get(cur_r, cur_c)) {
                --cur_c;
                ans = cur_r;
            }
            else {
                ++cur_r;
            }
        }
        return ans;
    }
};