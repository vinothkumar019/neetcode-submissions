class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string& t1, string& t2){
        if(i == t1.size() || j == t2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j]) return dp[i][j]=1+solve(i+1,j+1,t1,t2);

        return dp[i][j]=max(solve(i+1,j,t1,t2),solve(i,j+1,t1,t2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2);
    }
};
