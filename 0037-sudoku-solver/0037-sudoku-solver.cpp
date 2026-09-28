class Solution {
public:

   

    bool isSafe(vector<vector<char>>&a, int row, int col, char dig){
        //horizontal

        for(int j = 0; j < 9; j++){
            if(a[row][j] == dig){
                return false;
            }
        }

        //vertical
        for(int i = 0; i < 9; i++){
            if(a[i][col] == dig){
                return false;
            }
        }

        //grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i = srow; i < srow+3; i++){
            for(int j = scol; j < scol+3; j++){
                if(a[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>&a, int row, int col){
        if(row == 9){
            return true;
        }

        int nextRow = row; 
        int nextCol = col + 1;
        if(nextCol == 9){
            nextRow = row + 1;
            nextCol = 0;
        }

        if(a[row][col] != '.'){
            return solve(a,nextRow,nextCol);
        }

        for(char dig = '1'; dig <= '9'; dig++){
            if(isSafe(a,row,col,dig)){
                a[row][col] = dig;
                if(solve(a,nextRow,nextCol)){
                    return true;
                }

                a[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
       solve(board,0,0);

    }
};