class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int l = 0, ans = 0;
        for(int r = 0; r < fruits.size(); ++r) {
            auto &f = fruits[r];
            while(basket.size() >= 2 && basket.find(f) == basket.end()) {
                --basket[fruits[l]];
                if(basket[fruits[l]] == 0)
                    basket.erase(fruits[l]);
                ++l;
            }
            ++basket[fruits[r]];
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};