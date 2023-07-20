class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (auto x : asteroids) {
            bool still_there = true;
            while(ans.size()) {
                if(ans.back() > 0 && x > 0) {
                    break;
                }
                else if(ans.back() < 0 && x < 0) {
                    break;
                }
                else if(ans.back() < 0 && x > 0) {
                    break;
                }
                else if(ans.back() > 0 && x < 0) {
                    if(ans.back() > -x) {
                        still_there = false;
                        break;
                    }
                    else if(ans.back() < -x) {
                        ans.pop_back();
                    }
                    else { // ==
                        ans.pop_back();
                        still_there = false;
                        break;
                    }
                }
            }
            if(still_there) ans.push_back(x);
        }
        return ans;
    }
};
