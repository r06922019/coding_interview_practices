class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        for (int i = 0; i < triangle.size() - 1; ++i)
        {
            auto &vec = triangle[i], &vec1 = triangle[i + 1];
            vec1[0] += vec[0];
            for (int j = 1; j < vec.size(); ++j)
                vec1[j] += min(vec[j - 1], vec[j]);
            vec1.back() += vec.back();
        }
        auto &last = triangle.back();
        return *min_element(last.begin(), last.end());
    }
};