class Pos {
public:
    int i, j;

    Pos(Pos &p) {
        i = p.i;
        j = p.j;
    }

    Pos(int _i, int _j) {
        this->i = _i;
        this->j = _j;
    }

    void add_both() {
        ++i, ++j;
    }

    void minus_both() {
        --i, --j;
    }

    void assign_values(const Pos &val) {
        i = val.i;
        j = val.j;
    }

    static Pos average_pos(const Pos &a, const Pos &b) {
        int i_ = a.i + (b.i-a.i)/2;
        int j_ = a.j + (b.j-a.j)/2;
        return Pos(i_, j_);
    }

    static void swap_with_pos(vector<vector<int>>& mat, const Pos &a, const Pos &b) {
        swap(mat[a.i][a.j], mat[b.i][b.j]);
    }

    friend bool operator ==(const Pos &a, const Pos &b) {
        return (a.i == b.i) && (a.j == b.j);
    }

    friend bool operator !=(const Pos &a, const Pos &b) {
        return !(a == b);
    }

    friend bool operator <(const Pos &a, const Pos &b) {
        return (a.i < b.i) && (a.j < b.j);
    }

    friend bool operator >(const Pos &a, const Pos &b) {
        return (a.i > b.i) && (a.j > b.j);
    }

    int get_value(const vector<vector<int>>& mat) {
        return mat[i][j];
    }
};

class Solution {
public:

    void qsort(vector<vector<int>>& mat, Pos &front, Pos &back) {
        // base case
        if(back.i - front.i <= 0) return ;
        if(back.i - front.i == 1) {
            if(back.get_value(mat) < front.get_value(mat)) {
                Pos::swap_with_pos(mat, front, back);
            }
            return ;
        }
        Pos mid = Pos::average_pos(front, back);
        int pivot_value = mid.get_value(mat);
        Pos::swap_with_pos(mat, mid, back); // pivot now at back
        Pos moving_front(front), moving_back(back);
        while(moving_front < moving_back) {
            if(moving_front.get_value(mat) <= pivot_value) {
                moving_front.add_both();
            }
            else if(moving_back.get_value(mat) >= pivot_value ) {
                moving_back.minus_both();
            }
            else {
                Pos::swap_with_pos(mat, moving_front, moving_back);
            }
        }

        Pos::swap_with_pos(mat, moving_front, back);
        moving_front.minus_both();
        qsort(mat, front, moving_front);
        moving_back.add_both();
        qsort(mat, moving_back, back);
        return;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0) return mat;
        int n = mat[0].size();
        if(n == 0) return mat;
        for(int i = 0; i < m; ++i) {
            int num_elements = min(m-i, n-0)-1;
            Pos front(i, 0), back(i + num_elements, num_elements);
            qsort(mat, front, back);
        }
        for(int j = 1; j < n; ++j) {
            int num_elements = min(m-0, n-j)-1;
            Pos front(0, j), back(num_elements, j + num_elements);
            qsort(mat, front, back);
        }
        return mat;
    }
};