class Solution {
public:
    int solve(int n , vector<vector<int>> &dp, vector<int>arr, int i , int j){
        if(i + 1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int res =  INT_MAX;
        for(int k = i + 1; k < j; k++){
            res = min(res, solve(n, dp, arr, i, k) + solve(n, dp, arr, k, j) + arr[i]*arr[k]*arr[j]);
        }
        dp[i][j] = res;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& arr) {
        int N=arr.size();
        vector<vector<int>> dp;
        for(int i = 0; i < N; i++){
            vector<int> res (N, -1);
            dp.push_back(res);
        }
        return solve(N, dp, arr, 0 , N - 1 );
    }
};