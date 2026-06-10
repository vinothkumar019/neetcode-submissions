class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    bool isValid(int row, int col,int n){
    for(int r = 0; r < row; r++){
        if(board[r][col] == 'Q')
            return false;
    }
    int r = row - 1;
    int c = col - 1;

    while(r >= 0 && c >= 0){
        if(board[r][c] == 'Q')
            return false;

        r--;
        c--;
    }
    r = row - 1;
    c = col + 1;

    while(r >= 0 && c < n){
        if(board[r][c] == 'Q')
            return false;

        r--;
        c++;
    }

    return true;
}
    void dfs(int n,int row){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row,col,n)){
                board[row][col]='Q';
                dfs(n,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        dfs(n,0);
        return res;
    }
};
