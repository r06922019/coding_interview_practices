class Solution
{
public:
    const string special = "!@#$%^&*()-+";
    bool is_special(char c)
    {
        for (auto s : special)
            if (s == c)
                return true;
        return false;
    }

    bool strongPasswordCheckerII(string password)
    {
        if (password.size() < 8)
            return false;
        bool has_lower = false, has_upper = false, has_digit = false, has_special = false;
        char prev = ' ';
        for (auto c : password)
        {
            if (islower(c))
                has_lower = true;
            if (isupper(c))
                has_upper = true;
            if (isdigit(c))
                has_digit = true;
            if (is_special(c))
                has_special = true;
            if (c == prev)
                return false;
            prev = c;
        }
        return has_lower && has_upper && has_digit && has_special;
    }
};