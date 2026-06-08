class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> row;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(row.count(board[i][j])) return false;

                row.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> col;
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                if(col.count(board[j][i])) return false;

                col.insert(board[j][i]);
            }
        }
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                unordered_set<char> box;
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j] == '.') continue;
                        if(box.count(board[i][j])) return false;
                        box.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
