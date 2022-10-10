class Solution {
public:

    void append_digit(vector<int> &vec, int num, int diff) {
        int digit = num % 10;
        int new_digit = digit + diff;
        if(new_digit >= 0 && new_digit <= 9) {
            vec.push_back(num * 10 + new_digit);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans = {0,1,2,3,4,5,6,7,8,9};
        --N;
        while(N > 0) {
            vector<int> new_ans;
            for(int &num : ans) {
                if(num > 0) {
                    append_digit(new_ans, num, K);
                    if(K > 0)
                        append_digit(new_ans, num, -K);
                }
            }
            ans = new_ans;
            --N;
        }
        return ans;
    }
};

/*
class Solution
{
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= 9; ++i)
        {
            q.push(i);
        }
        vector<int> diffs = {k};
        if (k != 0)
            diffs.push_back(-k);
        while (n > 1)
        {
            int q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                auto last = cur % 10;
                for (auto diff : diffs)
                {
                    if (last + diff <= 9 && last + diff >= 0)
                    {
                        q.push(cur * 10 + (last + diff));
                    }
                }
            }
            --n;
        }
        vector<int> ret;
        while (q.size())
        {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
*/