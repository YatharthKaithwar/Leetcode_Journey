class Solution {
private:
    bool DFS(vector<vector<char>>& board,int r,int c ,int index, string & word){
        if (index == word.length()) return true;

        if( r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[index] || board[r][c]=='$') return false; // returning false if the index is outside the board or the characer is already visited in the board //

        char temp = board[r][c]; // Storing it to temporary to restore it

        board[r][c] = '$'; //  mark as visited

        bool find = DFS(board, r+1, c, index+1, word) || DFS(board, r-1, c, index+1, word) ||
                    DFS(board, r, c+1, index+1, word) || DFS(board, r, c-1, index+1, word);
                    
        board[r][c]=temp;// restoring the character

        return find; //calling find function

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i =0; i<row; i++){
            for(int j =0;j<col;j++){
                if(board[i][j]==word[0] && DFS(board,i,j,0,word)) return true;// if word's 1st letter is same as board[index] letter//
            }
        } 
        return false;
    }
};