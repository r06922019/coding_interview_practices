class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0;
        int max_p = 0;
        for(auto &p : milestones) {
            total += p;
            max_p = max(max_p, p);
        }
        if(max_p > (total+1)/2) // overflow
            return 2*(total-max_p)+1;
        return total;
    }
};