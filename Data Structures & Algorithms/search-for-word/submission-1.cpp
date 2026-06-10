class Solution {
public:
    bool dfs(int r,int c,int idx,string word,vector<vector<char>>& board){
        if(idx == word.size()){
            return true;
        }
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx])
        return false;
        char temp=board[r][c];
        board[r][c]='#';
        bool found=dfs(r+1,c,idx+1,word,board) || dfs(r-1,c,idx+1,word,board)
        || dfs(r,c+1,idx+1,word,board) || dfs(r,c-1,idx+1,word,board);

        board[r][c]=temp;

        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++){
    for(int j=0;j<board[0].size();j++){

        if(dfs(i,j,0,word,board))
            return true;
    }
}

return false;
    }
};
