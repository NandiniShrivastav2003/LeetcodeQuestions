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
                if(safe(board,c,i,j)){
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

    bool safe(vector<vector<char>>&board,char c,int i,int j){
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
         
         
     
        for(int p=nr;p<nr+3;p++){
            for(int q=nc;q<nc+3;q++){
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