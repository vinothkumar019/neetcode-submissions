class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int num:nums){
            mp[num]++;
        }
    priority_queue<pair<int, int>> pq;

    for(auto& i:mp){
        pq.push({i.second,i.first});
    }

    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }

        return res;
    }
};
