class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
       unordered_set<string>s;
        string temp="";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){ 
                    int val=board[i][j]-'0';
                    temp="row"+to_string(i)+to_string(val);
                    if(s.find(temp) != s.end()){
                        return false;
                    }
                    s.insert(temp);
                     temp="col"+to_string(j)+to_string(val);
                     if(s.find(temp) != s.end()){
                        return false;
                    }
                     s.insert(temp);
                    int box_no=(i/3)*3+(j/3);
                    temp="box"+to_string(box_no)+to_string(val);
                     if(s.find(temp) != s.end()){
                        return false;
                    }
                     s.insert(temp);
                }
                
            }
        }
        return true;
    }
};