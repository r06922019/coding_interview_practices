class Node {
public:
    int key;
    int value;
    int freq;

    Node (int k, int v, int f) {
        key = k;
        value = v;
        freq = f;
    }
};

class LFUCache {
    unordered_map<int, list<Node>::iterator> key_to_iter;
    unordered_map<int, list<Node>> freq_to_list;
    int cap = 0;
    int min_freq = 1;
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(key_to_iter.find(key) == key_to_iter.end()) {
            return -1;
        }
        return this->touch(key);
    }

    int touch(int key) {
        int value = key_to_iter[key]->value;
        int freq = key_to_iter[key]->freq;

        list<Node> &old_data = freq_to_list[freq];
        old_data.erase(key_to_iter[key]);
        if(this->min_freq == freq && old_data.size() == 0)
            ++this->min_freq;

        ++freq;
        this->ensure_list_exist(freq);
        list<Node> &new_data = freq_to_list[freq];
        key_to_iter[key] = new_data.insert(new_data.begin(), {key, value, freq});
        return value;
    }

    void put(int key, int value) {
        if(key_to_iter.find(key) != key_to_iter.end()) {
            this->touch(key);
            key_to_iter[key]->value = value;
            return;
        }

        if(cap > 0) { // not found
            if(key_to_iter.size() == cap) { // full, need to pop
                list<Node> &data = freq_to_list[this->min_freq];
                int del_key = data.back().key;
                data.erase(key_to_iter[del_key]);
                key_to_iter.erase(del_key);
            }

            this->ensure_list_exist(1);
            list<Node> &cur_list = freq_to_list[1];
            key_to_iter[key] = cur_list.insert(cur_list.begin(), {key, value, 1});
            this->min_freq = 1;
        }

        return ;
    }

    void ensure_list_exist(int freq) {
        if(freq_to_list.find(freq) == freq_to_list.end()) {
            freq_to_list[freq] = list<Node>();
        }
        return ;
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */