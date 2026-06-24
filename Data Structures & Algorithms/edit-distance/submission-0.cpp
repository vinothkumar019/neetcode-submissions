class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string& word1,string& word2){
        int n=word1.size();
        int m=word2.size();
        if(i == n) return m-j;
        if(j == m) return n-i;

        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j]=solve(i+1,j+1,word1,word2);

        return dp[i][j]=1 + min({
            solve(i+1,j,word1,word2),
            solve(i,j+1,word1,word2),
            solve(i+1,j+1,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        
        return solve(0,0,word1,word2);
    }
};
