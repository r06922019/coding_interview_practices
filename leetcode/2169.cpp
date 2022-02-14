class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        return solve(num1, num2, 0);
    }

    int solve(int num1, int num2, int steps)
    {
        if (num1 == 0 || num2 == 0)
            return steps;
        if (num1 >= num2)
            return solve(num1 - num2, num2, steps + 1);
        return solve(num1, num2 - num1, steps + 1);
    }
};