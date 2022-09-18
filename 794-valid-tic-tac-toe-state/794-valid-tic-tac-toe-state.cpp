class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xs = count(board, 'X'), os = count(board, 'O');
        return xs == os ? !winning(board, 'X') : xs == os + 1 ? !winning(board, 'O') : false;
    }
    
    bool winning(vector<string> &board, char c) {
        for(int i = 0; i < 3; i++)
            if(board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        for(int j = 0; j < 3; j++)
            if(board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if(board[2][0] == c && board[1][1] == c && board[0][2] == c) return true;
        return false;
    }
    
    int count(vector<string> &board, char c) {
        int cnt = 0;
        for(auto r : board)
            for(auto val : r)
                cnt += (c == val);
        return cnt;
    }
    
};