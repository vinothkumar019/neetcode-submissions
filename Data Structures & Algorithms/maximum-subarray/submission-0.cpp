class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0;
        int maxi=nums[0];

        for(int x:nums){
            cur += x;
            maxi=max(maxi,cur);
            if(cur < 0) cur=0;
        }
        return maxi;
    }
};
