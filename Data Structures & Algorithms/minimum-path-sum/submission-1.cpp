class Solution {
public:
    vector<vector<int>> dp;
    int solve(int row,int col,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(row >= n||col >= m) return INT_MAX;
        if(row == n-1 && col == m-1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int right=solve(row,col+1,grid);
        int down=solve(row+1,col,grid);
        return dp[row][col]=grid[row][col]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};