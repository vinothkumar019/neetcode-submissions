class Solution {
public:
    vector<int> dp;
    int coin(int amount, vector<int>& coins){
        if(amount == 0)
            return 0;

        if(amount < 0)
            return 1e9;

        int ans = 1e9;
        if(dp[amount] != -1) return dp[amount];
        for(int i = 0; i < coins.size(); i++){
            ans = min(ans,1 + coin(amount - coins[i], coins));
        }

        return dp[amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount+1,-1);

        int ans = coin(amount, coins);

        return ans == 1e9 ? -1 : ans;
    }
};