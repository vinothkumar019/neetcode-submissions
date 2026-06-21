class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int target,vector<int>& nums){
        int n=nums.size();
        if(target==0) return true;
        if(i == n) return false;
        if(dp[i][target] != -1) return dp[i][target];
        bool notTake=solve(i+1,target,nums);
        bool take=false;
        if(nums[i] <= target){
            take=solve(i+1,target-nums[i],nums);
        }
        return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2) return false;
        int target=sum/2;
        dp.resize(n,vector<int>(target+1,-1));

        return solve(0,target,nums);
    }
};
