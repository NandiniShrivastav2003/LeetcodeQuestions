
        
    class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        
        int n=board.size();
        int start=1;
        vector<pair<int,int>>p(n*n+1);
        vector<int>columns(n);
        std::iota(columns.begin(),columns.end(),0);
        for(int i=n-1;i>=0;i--){
            for(auto column:columns){
                p[start++]={i,column};
            }
            reverse(columns.begin(),columns.end());
        }
        queue<int>q;
        q.push(1);
        vector<int>dist(n*n+1,-1);
        dist[1]=0;
        while(!q.empty()){
            int pos=q.front();
            q.pop();
            for(int curr=pos+1;curr<=min(pos+6,n*n);curr++){
              auto [x,y]=p[curr];
                int dest;
                if(board[x][y] != -1){
                 dest=board[x][y];
                }
                else{
                    dest=curr;
                }
                if(dist[dest] == -1){
                    dist[dest]=dist[pos]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];

    }
};