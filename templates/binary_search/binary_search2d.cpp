class Solution {
public:
    int binary_search(vector<int> &vec, int l, int r, int target) {
        if(l >= r) return l;
        int mid = l + (r-l)/2;
        if(target <= vec[mid])
            return binary_search(vec, l, mid, target);
        return binary_search(vec, mid+1, r, target);
    }

    bool helper(vector<vector<int>>& matrix, int target,
                int i_start, int i_end, int j_start, int j_end) {
        if(i_start >= i_end || j_start >= j_end) {
            return false;
        }
        // printf("i_start %d, i_end %d, j_start %d, j_end %d\n", i_start, i_end, j_start, j_end);
        int i_mid = i_start + (i_end - i_start)/2;
        int j_mid = binary_search(matrix[i_mid], j_start, j_end, target);
        // printf("j_mid = %d\n", j_mid);
        // if(j_mid < j_end) printf("j_mid = %d, matrix[i_mid][j_mid] = %d\n", j_mid, matrix[i_mid][j_mid]);
        if(j_mid < j_end && matrix[i_mid][j_mid] == target) return true;
        return helper(matrix, target, i_mid+1, i_end, j_start, j_mid) ||
            helper(matrix, target, i_start, i_mid, j_mid, j_end);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return helper(matrix, target, 0, m, 0, n);
    }

};
