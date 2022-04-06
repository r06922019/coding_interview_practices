class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int boats = 0;
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            ++boats;
            int cur_limit = limit, cur_people = 0;
            while (cur_people < 2 && l <= r && cur_limit >= people[r])
            {
                cur_limit -= people[r];
                --r;
                ++cur_people;
            }
            while (cur_people < 2 && l <= r && cur_limit >= people[l])
            {
                cur_limit -= people[l];
                ++l;
                ++cur_people;
            }
        }
        return boats;
    }
};