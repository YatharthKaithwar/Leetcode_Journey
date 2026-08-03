class Solution {
public: 
    bool isSafe(int row, int col, vector<string> &board, int n){
        int dupRow =row;
        int dupCol = col;

        while(row>=0 && col>=0){// checking upper left diagonal 
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row= dupRow;
        col= dupCol;
        while(col>=0){// checking left columns
            if(board[row][col]== 'Q')return false;
            col--;
        }
        row= dupRow;
        col= dupCol;
        while(row<n &&col>=0){// checking lower left diagonals
            if(board[row][col]== 'Q')return false;
            row++;
            col--;
        }
        return true;
    }    
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0 ; row<n ; row++){// checking row
            if(isSafe(row,col,board,n)){// if safe 
                board[row][col]= 'Q';// puuting queen in the board at right place
                solve(col+1, board, ans, n);// solve the next column to place queen
                board[row][col] = '.';// fill back the baord empty for backtracking
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};