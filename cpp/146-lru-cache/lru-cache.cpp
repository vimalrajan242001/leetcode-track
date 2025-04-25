class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(storage.find(key) != storage.end()){
            RemoveFromOrderAndMakeItRecentlyUsed(key);
            return storage[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(storage.find(key) != storage.end()){
            RemoveFromOrderAndMakeItRecentlyUsed(key);
            storage[key] = value;
        }
        else{
            if(storage.size() == cap){
                auto front = order.front();
                order.erase(order.begin());
                storage.erase(front);
            }
            storage[key] = value;
            order.push_back(key);
        }
    }

private:
    int cap;
    unordered_map<int,int> storage;
    vector<int> order;
    
    void RemoveFromOrderAndMakeItRecentlyUsed(int key){
        auto it = std::find(order.begin(), order.end(), key);
        if (it != order.end()) order.erase(it);
        order.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */