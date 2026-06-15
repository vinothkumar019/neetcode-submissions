class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto [i,j]= q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr < 0 || nr >= r || nc<0 || nc >= c) continue;

                if(grid[nr][nc] != 2147483647) continue;

                grid[nr][nc]=grid[i][j]+1;
                q.push({nr,nc});
            }
        }
    }
};
