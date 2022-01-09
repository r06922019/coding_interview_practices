/*
2133. Check if Every Row and Column Contains All Numbers
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
*/

class Solution
{
public:
    bool checkValid(vector<vector<int> > &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> seen;
            for (int j = 0; j < n; ++j)
            {
                seen.insert(matrix[i][j]);
            }
            if (seen.size() < n)
                return false;
        }

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> seen;
            for (int j = 0; j < n; ++j)
            {
                seen.insert(matrix[j][i]);
            }
            if (seen.size() < n)
                return false;
        }

        return true;
    }
};