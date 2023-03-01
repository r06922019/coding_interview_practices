class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.size() == 0)
            return 0;
        int index = 0, num = 0;
        bool is_positive = true;

        // ignore spaces
        while (isspace(s[index]))
            ++index;

        // check if we have sign
        if (s[index] == '+' || s[index] == '-' || isdigit(s[index]))
        {
            // eat sign
            if (s[index] == '+' || s[index] == '-')
            {
                if (s[index] == '-')
                {
                    is_positive = false;
                }
                ++index;
            }

            // eat digits
            while (isdigit(s[index]))
            {
                int digit = s[index] - '0';
                if (is_positive)
                {
                    // num = num * 10 + digit;
                    if (num > INT_MAX / 10)
                        return INT_MAX;
                    num = num * 10;
                    if (num > INT_MAX - digit)
                        return INT_MAX;
                    num = num + digit;
                }
                else
                {
                    // num = num * 10 - digit;
                    if (num < INT_MIN / 10)
                        return INT_MIN;
                    num = num * 10;
                    if (num < INT_MIN + digit)
                        return INT_MIN;
                    num = num - digit;
                }
                ++index;
            }
        }

        return num;
    }
};