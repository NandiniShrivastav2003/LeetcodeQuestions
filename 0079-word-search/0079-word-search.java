class Solution {
    public boolean check(char[][] board,String word,int i,int j,int idx){
        if(idx == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length){
            return false;
        }
        
        if(board[i][j] != word.charAt(idx)){
            return false;
        }
        board[i][j]='*';
       
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        for(int k=0;k<dx.length;k++){
           boolean ans= check(board,word,i+dx[k],j+dy[k],idx+1);
            if(ans == true){
                return true;
            }
           
        }
        
         board[i][j]=word.charAt(idx);
        return false;
        
        
    }
    public boolean exist(char[][] board, String word) {
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j] == word.charAt(0)){
                    boolean res=check(board,word,i,j,0);
                    if(res == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}