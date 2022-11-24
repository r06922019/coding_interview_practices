class Solution
{
public:
    int removeDuplicates(vector<int> &v)
    {
        int len = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (i == 0 || v[i] != v[i - 1])
                v[len++] = v[i];
        }
        return len;
    }
};