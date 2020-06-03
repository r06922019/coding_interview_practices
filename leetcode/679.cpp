/*



*/

class Fraction {

public:
    int up, down;

    Fraction(int _u, int _d) {
        up = _u;
        down = _d;
        this->simplify();
    }

    Fraction(int _u) {
        up = _u;
        down = 1;
    }

    void simplify() {
        int gcd = get_gcd(abs(up), abs(down));
        this->up /= gcd;
        this->down /= gcd;
    }

    bool can_eval_int() {
        return (up % down == 0);
    }

    int eval_int() {
        if(this->can_eval_int()) return up / down;
        return -1;
    }

    static int get_gcd(int a, int b) {
        if(a == 0 || b == 0) return 1;
        if(a%b == 0) return b;
        return get_gcd(b, a%b);
    }

    static Fraction add(Fraction a, Fraction b) {
        int down = a.down * b.down;
        int up = a.up * b.down + b.up * a.down;
        return Fraction(up, down);
    }

    static Fraction minus(Fraction a, Fraction b) {
        int down = a.down * b.down;
        int up = a.up * b.down - b.up * a.down;
        return Fraction(up, down);
    }

    static Fraction mul(Fraction a, Fraction b) {
        int down = a.down * b.down;
        int up = a.up * b.up;
        return Fraction(up, down);
    }

    static Fraction div(Fraction a, Fraction b) {
        int down = a.down * b.up;
        int up = a.up * b.down;
        return Fraction(up, down);
    }

};

class Solution {
public:
    int TARGET = 24;

    bool judgePoint24(vector<int>& nums) {
        // vector<Fraction> fractions;
        // for(int &num : nums) {
        //     fractions.push_back(Fraction(num));
        // }

        // return helper(fractions);

        sort(nums.begin(), nums.end());
        vector<double> nums_d(nums.begin(), nums.end());
        return helper1(nums_d);
    }

    bool helper1(vector<double> nums) {
        int n = nums.size();
        if(n == 1) return (abs(nums[0] - TARGET)) < EPS;

        do {
            vector<double> tmp;
            for(int i = 0; i < n-2; ++i) {
                tmp.push_back(nums[i]);
            }

            tmp.push_back(0);
            double &a = nums[n-2], &b = nums[n-1];
            for(double new_num : {a+b, a-b, a*b}) {
                tmp.back() = new_num;
                if(helper1(tmp)) return true;
            }
            if(abs(nums[n-1]) > EPS) {
                tmp.back() = (nums[n-2] / nums[n-1]);
                if(helper1(tmp)) return true;
            }

        }while(next_permutation(nums.begin(), nums.end()));

        return false;
    }

    bool helper(vector<Fraction> fractions) {
        if(fractions.size() == 1) {
            return fractions.front().eval_int() == TARGET;
        }

        for(int i = 0; i < fractions.size(); ++i) {
            for(int j = i+1; j < fractions.size(); ++j) {
                // gather the rest
                vector<Fraction> next;
                for(int k = 0; k < fractions.size(); ++k) {
                    if(k != i && k != j) {
                        next.push_back(fractions[k]);
                    }
                }

                Fraction &a = fractions[i], &b = fractions[j];

                next.push_back(Fraction::add(a, b));
                if(helper(next)) return true;
                next.pop_back();

                next.push_back(Fraction::minus(a, b));
                if(helper(next)) return true;
                next.pop_back();

                next.push_back(Fraction::minus(b, a));
                if(helper(next)) return true;
                next.pop_back();

                next.push_back(Fraction::mul(a, b));
                if(helper(next)) return true;
                next.pop_back();

                if(b.eval_int()) {
                    next.push_back(Fraction::div(a, b));
                    if(helper(next)) return true;
                    next.pop_back();
                }

                if(a.eval_int()) {
                    next.push_back(Fraction::div(b, a));
                    if(helper(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

};