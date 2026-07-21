class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& obstacleGrid,int row,int col){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if (row >= n || col >= m)
    return 0;

if (obstacleGrid[row][col] == 1)
    return 0;

if (row == n - 1 && col == m - 1)
    return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int right=solve(obstacleGrid,row,col+1);
        int down=solve(obstacleGrid,row+1,col);
        return dp[row][col]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(obstacleGrid,0,0);

    }
};