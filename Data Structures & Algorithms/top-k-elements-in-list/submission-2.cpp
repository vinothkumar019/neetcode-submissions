class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>> freq;

        for(auto it:mp){
            freq.push_back({it.second,it.first});
        }
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<k;i++){
            res.push_back(freq[i].second);
        }

        return res;
    }
};
