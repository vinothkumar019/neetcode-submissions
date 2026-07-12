class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int miss=1;
        for(int i=0;i<n;i++){
            if(nums[i]<miss) continue;
            if(nums[i] == miss) miss++;
            else 
                break;
        }
        return miss;
    }
};