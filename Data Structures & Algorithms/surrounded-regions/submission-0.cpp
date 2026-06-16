class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c){
        if(r < 0 || r >=  board.size() || c < 0 || c >= board[0].size()) return;

        if(board[r][c] != 'O') return;

        board[r][c]='T';
        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();

        for(int r=0;r<rows;r++){
            dfs(board,r,0);
            dfs(board,r,cols-1);
        }
        for(int c=0;c<cols;c++){
            dfs(board,0,c);
            dfs(board,rows-1,c);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O')
                    board[i][j]='X';
                else if(board[i][j] == 'T')
                    board[i][j]='O';
            }
        }
    }
};
