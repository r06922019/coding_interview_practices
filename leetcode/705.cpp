const int BUCKETS = 1000;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<list<int>> data;
    MyHashSet() : data(BUCKETS, list<int>()) {

    }

    void add(int key) {
        int bucket = (key / BUCKETS) % BUCKETS;
        list<int>::iterator find_it = find_in_bucket(bucket, key);
        if(find_it == data[bucket].end()) {
            data[bucket].push_back(key);
        }
    }

    list<int>::iterator find_in_bucket(int bucket, int key) {
        list<int> &l = data[bucket];
        for(auto it = l.begin(); it != l.end(); ++it) {
            if((*it) == key) {
                return it;
            }
        }
        return l.end();
    }

    void remove(int key) {
        int bucket = (key / BUCKETS) % BUCKETS;
        list<int>::iterator find_it = find_in_bucket(bucket, key);
        if(find_it != data[bucket].end()) {
            data[bucket].erase(find_it);
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucket = (key / BUCKETS) % BUCKETS;
        list<int>::iterator find_it = find_in_bucket(bucket, key);
        return(find_it != data[bucket].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */