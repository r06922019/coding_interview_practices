class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> buckets[1000];
    MyHashSet() {

    }

    void add(int key) {
        int bucket_index = key % 1000;
        for(auto &x : buckets[bucket_index])
            if(x == key)
                return ;
        buckets[bucket_index].push_back(key);
    }

    void remove(int key) {
        int bucket_index = key % 1000;
        auto &vec = buckets[bucket_index];
        int index = -1;
        for(int i = 0; i < vec.size() && index < 0; ++i) {
            if(vec[i] == key) {
                index = i;
            }
        }
        if(index >= 0) {
            vec[index] = vec.back();
            vec.pop_back();
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucket_index = key % 1000;
        for(auto &x : buckets[bucket_index])
            if(x == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */