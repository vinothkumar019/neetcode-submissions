class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>_mp;
        for(int i:nums){
            if(_mp.find(i) != _mp.end())
                return true;
            
            _mp.insert(i);
        }
        return false;
    }
};