
//         int n=board.size();
//         int start=1;
//         vector<pair<int,int>>p(n*n+1);
//         vector<int>columns(n);
//         std::iota(columns.begin(),columns.end(),0);
//         for(int i=n-1;i>=0;i--){
//             for(auto column:columns){
//                 p[start++]={i,column};
//             }
//             reverse(columns.begin(),columns.end());
//         }
//         queue<int>q;
//         q.push(1);
//         vector<int>dist(n*n+1,-1);
//         dist[1]=0;
//         while(!q.empty()){
//             int pos=q.front();
//             q.pop();
//             for(int curr=pos+1;curr<=min(curr+6,n*n);curr++){
//               auto [x,y]=p[curr];
//                 int dest;
//                 if(board[x][y] != -1){
//                  dest=board[x][y];
//                 }
//                 else{
//                     dest=curr;
//                 }
//                 if(dist[dest] == -1){
//                     dist[dest]=dist[pos]+1;
//                     q.push(dest);
//                 }
//             }
//         }
//         return dist[n*n];
        
        class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];

    }
};