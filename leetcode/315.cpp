class Item {
public:
    int index, value;
    Item(int _i, int _v) {
        index = _i;
        value = _v;
    }

    Item(Item &&item) {
        index = move(item.index);
        value = move(item.value);
    }

    Item& operator=(Item&& other) {
        index = move(other.index);
        value = move(other.value);
        return *this;
    }
};

class Solution {
public:
    void merge_sort(vector<Item> &items, int start, int end, vector<int> &ans) {
        if(end - start <= 1) return;

        int mid = start + ((end-start) >> 1);
        merge_sort(items, start, mid, ans);
        merge_sort(items, mid, end, ans);

        vector<Item> tmp;
        tmp.reserve(end-start);
        int l = start, r = mid;
        while(l < mid || r < end) {
            if(r >= end || (l < mid && items[l].value <= items[r].value)) {
                ans[items[l].index] += r - mid;
                tmp.push_back(move(items[l]));
                ++l;
            }
            else {
                tmp.push_back(move(items[r]));
                ++r;
            }
        }
        for(int i = start; i < end; ++i) {
            items[i] = move(tmp[i-start]);
        }
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<Item> items;
        for(int i = 0; i < nums.size(); ++i) {
            items.emplace_back(i, nums[i]);
        }
        vector<int> ans(nums.size(), 0);
        merge_sort(items, 0, items.size(), ans);
        return ans;
    }
};