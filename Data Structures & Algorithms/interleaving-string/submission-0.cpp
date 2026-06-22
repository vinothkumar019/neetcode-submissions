class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int j,string& s1, string& s2, string& s3){
        int n=s1.size();
        int m=s2.size();
        if(i == n && j == m) return true;

        if(dp[i][j] != -1) return dp[i][j];
        bool ans=false;
        if(i < n && s1[i] == s3[i+j]) ans |= solve(i+1,j,s1,s2,s3);
        if(j < m && s2[j] == s3[i+j]) ans |= solve(i,j+1,s1,s2,s3);

        return dp[i][j]=ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));

        return solve(0,0,s1,s2,s3);
    }
};
