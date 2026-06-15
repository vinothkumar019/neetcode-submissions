class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        while(!q.empty() && fresh >0){
            int size=q.size();
            for(int k=0;k<size;k++){
                auto [i,j]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nr=i+dr[d];
                    int nc=j+dc[d];
                    if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                    if(grid[nr][nc] != 1) continue;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            count++;
        }
        return fresh==0?count:-1;

    }
};
