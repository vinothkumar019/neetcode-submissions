class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int buy,vector<int>& prices){
        int n=prices.size();
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+solve(i+1,0,prices),solve(i+1,1,prices));
        }
        else{
            profit= max(
        prices[i] + solve(i+2, 1,prices),  // sell
        solve(i+1, 0,prices)  );
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
       dp.resize(prices.size(), vector<int>(2, -1));
        return solve(0,1,prices);
    }
};
