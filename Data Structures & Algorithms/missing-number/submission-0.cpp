class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
         int ans1=n;
        int ans2=0;
        for(int i=0;i<n;i++){
            ans1 ^= i;
            ans2 ^= nums[i];
        }
        return ans1^ans2;
    }
};
