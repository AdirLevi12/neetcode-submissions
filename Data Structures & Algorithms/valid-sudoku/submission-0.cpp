class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ROWS = 9;
        int COLS = 9;
        int SQUARES = 9;
        vector<unordered_set<char>> rows(ROWS);
        vector<unordered_set<char>> cols(COLS);
        map<pair<int,int>, unordered_set<char>> squares;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    //check the rows rule:
                    if(rows[i].find(board[i][j]) != rows[i].end()){
                        return false;
                    }
                    rows[i].insert(board[i][j]);

                    //check the rows rule:
                    if(cols[j].find(board[i][j]) != cols[j].end()){
                        return false;
                    }
                    cols[j].insert(board[i][j]);

                    //check square rule:
                    pair<int,int> key = {i/3,j/3};
                    if(squares[key].count(board[i][j]) != 0){
                        return false;
                    }
                    squares[key].insert(board[i][j]);
                }  
            }
        }
        return true;
        
    }
};
