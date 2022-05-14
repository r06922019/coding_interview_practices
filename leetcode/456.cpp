class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        vector<int> min_indexs(nums.size(), -1);
        int min_index = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            min_indexs[i] = min_index;
            if (min_index == -1 || nums[i] < nums[min_index])
            {
                min_index = i;
            }
        }

        stack<int> st;
        for (int i = 0; i < nums.size(); ++i)
        {
            const auto &num = nums[i];
            while (st.size() && nums[st.top()] <= num)
            {
                st.pop();
            }
            if (st.size() && min_indexs[st.top()] != -1 && nums[min_indexs[st.top()]] < num)
            {
                return true;
            }
            st.push(i);
        }
        return false;
    }
};