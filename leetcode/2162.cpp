class Solution
{
public:
    int cal_cost(int start_at, int move_cost, int push_cost, int minutes, int seconds)
    {
        if (minutes > 99 || seconds > 99)
            return -1;
        char s[5] = {0};
        sprintf(s, "%02d%02d", minutes, seconds);
        int cur_pos = start_at, index = 0;
        int cost = 0;
        while (s[index] == '0')
            ++index;
        while (index < 4)
        {
            int to_push = s[index] - '0';
            if (to_push != cur_pos)
            {
                cur_pos = to_push;
                cost += move_cost;
            }
            cost += push_cost;
            ++index;
        }
        return cost;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int ans = -1;
        for (int i = 0; i <= targetSeconds / 60; ++i)
        {
            int minutes = i;
            int seconds = targetSeconds - i * 60;
            int tmp = cal_cost(startAt, moveCost, pushCost, minutes, seconds);
            if (tmp >= 0 && (ans == -1 || ans > tmp))
                ans = tmp;
        }

        return ans;
    }
};