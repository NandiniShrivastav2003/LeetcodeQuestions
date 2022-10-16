class Solution {
public:
//     string convert(string temp){
        
//     }
    bool safe(vector<vector<char>>mat,int row,int col){
        int n=mat.size();
        for(int i=0;i<col;i++){
            if(mat[row][i] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(mat[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(mat[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void NQueen(int n,vector<string>temp,vector<vector<string>>&ans,int i,string res,vector<vector<char>>mat){
        if(i == n){
            for(int i=0;i<n;i++){
                string v="";
                for(int j=0;j<n;j++){
                v+=mat[i][j];
                    
                    
                }
               // cout<<v<<endl;
                temp.push_back(v);
          
            }
                ans.push_back(temp);
                  temp.clear();

            return ;
            
        }
        for(int j=0;j<n;j++){
        if(safe(mat,j,i)){
            mat[j][i]='Q';
                NQueen(n,temp,ans,i+1,res+to_string(j),mat);
            mat[j][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>>mat(n,vector<char>(n,'.'));
        vector<string>temp;
        vector<vector<string>>ans;
        NQueen(n,temp,ans,0,"",mat);
        return ans;
    }
};