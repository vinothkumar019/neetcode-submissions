class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 1;

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int k=0;k<4;k++){

        int nx = i + dx[k];
        int ny = j + dy[k];

        if(nx<0 || nx>=n || ny<0 || ny>=m)
            continue;

        if(matrix[nx][ny] > matrix[i][j])
            ans = max(ans,
                      1 + solve(nx,ny,matrix));
    }

    return dp[i][j] = ans;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));

        int ans = 0;
        int n=matrix.size();
        int m=matrix[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        ans = max(ans, solve(i,j,matrix));
    }
}

return ans;
    }
};
