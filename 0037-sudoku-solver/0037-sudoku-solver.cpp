class Solution {
public:
    bool solve(vector<vector<char>>&board,int i,int j){
        if(i == 9){
            return true ;
        }
        if(j == 9){
            //i=i+1;
           // j=0;
            return solve(board,i+1,0);
        }
        if(board[i][j] != '.'){
            return solve(board,i,j+1);
        }
        //if(board[i][j] == '.'){
            for(char c='1';c<='9';c++){
                if(isValid(board,i,j,c)){
                    board[i][j]=c;
                    if(solve(board,i,j+1)){
                        return true;
                    }
                    board[i][j]='.';
                }
            }
        return false;
    
       // }
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    // row check
    for(int i = 0; i < 9; i++) 
		if(board[i][col] == c) 
			return false;
	// col check
    for(int i = 0; i < 9; i++) 
		if(board[row][i] == c) 
			return false;
    // box check
    int x0 = (row/3) * 3, y0 = (col/3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[x0 + i][y0 + j] == c) return false;
        }
    }
    return true;
}
    bool safe(vector<vector<char>>board,char c,int i,int j){
        int nr=(i/3)*3;
        int nc=(j/3)*3;
     for(int x=0;x<9;x++){
         if(board[i][x] == c){
             return false;
         }
     }
        for(int x=0;x<9;x++){
         if(board[x][j] == c){
             return false;
         }
        }
         //for finding submatrix wala corner every submatrix of size 3*3 is (i/3)*3+(j/3)*3;ex-7,4 find val -- > (7/3)*3=6 so row =6 & col=(4/3)*3=3
         
         
     
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                if(board[p][q] == c){
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};