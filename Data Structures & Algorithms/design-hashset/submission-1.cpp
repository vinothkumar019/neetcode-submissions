class MyHashSet {
public:
    vector<int> nums;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))
        nums.push_back(key);
    }
    
    void remove(int key) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                nums.erase(nums.begin()+i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key) return true;
        }
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