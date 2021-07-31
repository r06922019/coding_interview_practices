class LRUCache {
public:
    list<pair<int, int>> l; // record k,v pairs
    unordered_map<int, list<pair<int, int>>::iterator> key_to_kv_iter;
    int capacity = 0;

    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    int touch(int key, int val) {
        if(key_to_kv_iter.find(key) != key_to_kv_iter.end()) {
            l.erase(key_to_kv_iter[key]);
        }
        key_to_kv_iter[key] = l.insert(l.begin(), {key,val});
        return val;
    }

    int get(int key) {
        if(key_to_kv_iter.find(key) == key_to_kv_iter.end()) return -1;
        return touch(key, key_to_kv_iter[key]->second);
    }

    void put(int key, int value) {
        while(key_to_kv_iter.find(key) == key_to_kv_iter.end() && key_to_kv_iter.size() >= capacity) {
            key_to_kv_iter.erase(l.back().first);
            l.pop_back();
        }
        touch(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */