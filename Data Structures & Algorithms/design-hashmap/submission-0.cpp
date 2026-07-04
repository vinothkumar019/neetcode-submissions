class MyHashMap {
public:
    vector<pair<int,int>> nums;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
    for (auto &it : nums) {
        if (it.first == key) {
            it.second = value;
            return;
        }
    }
    nums.push_back({key, value});
}
    
    int get(int key) {
        for(auto &it:nums){
            if(it.first == key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i].first == key) {
                nums.erase(nums.begin()+i);
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