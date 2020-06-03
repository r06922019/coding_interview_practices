class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        // first discards as many whitespace characters as necessary
        // until the first non-whitespace character is found.
        while(isspace(str[index])) ++index;

        // takes an optional initial plus or minus sign
        // followed by as many numerical digits as possible,
        // and interprets them as a numerical value.
        if(str[index] == '+') {
            return parse_from(str, index+1, 1);
        }
        else if(str[index] == '-'){
            return parse_from(str, index+1, -1);
        }
        else if(isdigit(str[index])) {
            return parse_from(str, index, 1);
        }
        return 0;
    }

    int parse_from(string str, int index, int sign) {
        int num = 0;
        while(isdigit(str[index])) {
            int cur_digit = str[index]-'0';
            // num = num * 10 + cur_digit;
            if(sign > 0) { // positive number
                if(num > INT_MAX/10) {
                    return INT_MAX;
                }
                num *= 10;
                if(num > INT_MAX - cur_digit) {
                    return INT_MAX;
                }
                num += cur_digit;
            }
            else { // negative number
                if(num < INT_MIN/10) {
                    return INT_MIN;
                }
                num *= 10;
                if(num < INT_MIN + cur_digit) {
                    return INT_MIN;
                }
                num -= cur_digit;
            }
            ++index;
        }
        return num;
    }
};
