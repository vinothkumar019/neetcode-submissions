class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n+2,0);
        dp[0]=0;
        dp[1]=0;
        dp[2]=0;
        for(int i=n-1;i>=0;i--){
            dp[i] = max(
    nums[i] + dp[i+2],
    dp[i+1]
);
        }
        return dp[0];
    }
};
