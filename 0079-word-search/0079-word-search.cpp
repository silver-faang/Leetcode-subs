class Solution {
public:
    bool backtrack(vector<vector<char>> & board, string word, int i, int r ,int c){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[i]) return false;
        if(i==word.length()-1) return true;
        char temp=board[r][c];
        board[r][c]='#';
        bool found=backtrack(board,word,i+1,r-1,c)||
        backtrack(board,word,i+1,r+1,c)||
        backtrack(board,word,i+1,r,c-1)||
        backtrack(board,word,i+1,r,c+1);
        board[r][c]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(), c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]&& backtrack(board,word,0,i,j))
                 return true;
            }
        }
        return false;
    }
};