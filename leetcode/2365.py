class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        ans = 0
        prev_time = {}
        for task in tasks:
            if task in prev_time and ans - prev_time[task] <= space:
                ans = prev_time[task] + space + 1
            prev_time[task] = ans
            ans += 1
        return ans

'''
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        unordered_map<int, int> prev_time;
        for(auto task : tasks) {
            if(prev_time.find(task) != prev_time.end() && ans - prev_time[task] <= space) {
                ans = prev_time[task] + space + (long long)1;
            }
            prev_time[task] = ans;
            ++ans;
        }
        
        return ans;
    }
};
'''
