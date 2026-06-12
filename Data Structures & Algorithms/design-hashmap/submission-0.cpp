class MyHashMap {
public:
    int M;
    vector<list<pair<int,int>>> buckets;
    int getIndex(int key){
        return key % M;
    }
    MyHashMap() {
        M = 100000;
        buckets = vector<list<pair<int , int>>>(M , list<pair<int , int>>{});
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        for (auto& p : buckets[index]){
            if ( p.first == key){
                p.second = value;
                return;
            }
        }
        buckets[index].push_back({key,value});
    }
    
    int get(int key) {
            int index = getIndex(key);
            for (auto& p : buckets[index]){
                if ( p.first == key){
                    return p.second;
                }
            }
            return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto& bucket = buckets[index];
        for (auto itr = bucket.begin(); itr != bucket.end();itr ++){
            if (itr->first == key ){
                bucket.erase(itr);
                return;
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