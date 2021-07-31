class Solution {
public:
    string fractionToDecimal(int _n, int _d) {
        long numerator = _n;
        long denominator = _d;
        int sign = 1;
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)){
            sign = -1;
        }
        long int_part = sign * (numerator / denominator);
        long remainder = sign * (numerator % denominator);
        if(remainder == 0) return ((sign == -1)? "-":"") + to_string(int_part);

        string cur = to_string(int_part) + ".";
        unordered_map<long, string> remainder_to_accumulated_string;
        remainder_to_accumulated_string[remainder] = cur;
        while(remainder) {
            numerator = remainder * 10;
            int_part = (numerator / denominator);
            remainder = (numerator % denominator);
            cur += to_string(int_part);
            if(remainder_to_accumulated_string.find(remainder) != remainder_to_accumulated_string.end()) {
                return ((sign == -1)? "-":"") + remainder_to_accumulated_string[remainder] + "(" + cur.substr(remainder_to_accumulated_string[remainder].size()) + ")";
            }
            remainder_to_accumulated_string[remainder] = cur;
        }
        return ((sign == -1)? "-":"") + cur;
    }
};