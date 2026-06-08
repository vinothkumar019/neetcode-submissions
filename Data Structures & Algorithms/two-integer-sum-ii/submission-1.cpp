class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int ck=target-numbers[i];
            if(mp.count(ck)){
                res.push_back(mp[ck]+1);
                res.push_back(i+1);
            }
            mp[numbers[i]]=i;
        }
        return res;
    }
};
