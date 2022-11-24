class MyHashMap {
public:
    vector<vector<pair<int,int>>> data;
    
    
    MyHashMap() {
        data.resize(999);
    }
    
    void put(int key, int value) {
        int bucket = key % data.size();
        for (auto &p: data[bucket]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        data[bucket].push_back({key, value});
    }
    
    int get(int key) {
        int bucket = key % data.size();
        for (auto &p: data[bucket]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = key % data.size();
        int sz = data[bucket].size();
        for (int i = 0; i < sz; i++) {
            if (data[bucket][i].first == key) {
                data[bucket].erase(data[bucket].begin() + i);
                break;
            }
        }
    }   
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */