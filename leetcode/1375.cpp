class Solution {
public:
    int numTimesAllBlue(vector<int>& lights) {
        int n = lights.size(), cnt = 0, max_light_index = -1;
        for(int i = 0; i < n; ++i) {
            max_light_index = max(max_light_index, lights[i]);
            if(i+1 == max_light_index) ++cnt;
        }
        return cnt;
    }
};
