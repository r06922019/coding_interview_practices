class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> seen(2001, false);
        for(auto &num : arr) {
            ++seen[num+1000];
        }
        for(int num = -500; num <= 500; ++num) {
            int index = num+1000;
            if(num == 0) {
                if(seen[index] >= 2) return true;
            }
            else {
                int index2 = num*2 + 1000;
                if(seen[index] && seen[index2]) return true;
            }
        }
        return false;
    }
};