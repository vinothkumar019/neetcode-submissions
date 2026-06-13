class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c]==0) 
            return 0;
        grid[r][c]=0;
        return 1+dfs(grid,r-1,c)+dfs(grid,r+1,c)+dfs(grid,r,c-1)+dfs(grid,r,c+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int area=dfs(grid,i,j);
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
    }
};
