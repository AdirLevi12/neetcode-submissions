class Solution {
public:
    void mark(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == 'S' || board[i][j] == 'X'){
            return;
        }
        board[i][j] = 'S';
        mark(board,i,j+1);
        mark(board,i,j-1);
        mark(board,i+1,j);
        mark(board,i-1,j);
    }

    void finalScan(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            } 
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        //top row
        for(int i = 0; i < cols; i++){
            if(board[0][i] == 'O'){
                mark(board,0,i);
            }
        }
        //bottom row
        for(int i = 0; i < cols; i++){
            if(board[rows-1][i] == 'O'){
                mark(board,rows-1,i);
            }
        }
        //left col
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                mark(board,i,0);
            }
        }
        //right col
        for(int i = 0; i < rows; i++){
            if(board[i][cols-1] == 'O'){
                mark(board,i,cols-1);
            }
        }
        finalScan(board);
    }
};