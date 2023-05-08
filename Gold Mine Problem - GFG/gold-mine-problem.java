//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String inline[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(inline[0]);
            int m = Integer.parseInt(inline[1]);
            String inline1[] = in.readLine().trim().split("\\s+");
            int M[][] = new int[n][m];
            for(int i = 0;i < n*m;i++){
                M[i/m][i%m] = Integer.parseInt(inline1[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.maxGold(n, m, M));
        }
    }
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int goldmax(int arr[][], int i, int j, int ans,int dp[][]) {
        // if (i == arr.length - 1 && j == arr[0].length - 1) {
        //   //  System.out.println(ans);
        //     return ans;
        // }
        if (i < 0 || j < 0 || i >= arr.length || j >= arr[0].length) {
            return 0;

        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int a = 0;
        if (j + 1 >= 0 && j + 1 < arr[0].length) {
            a = goldmax(arr, i, j + 1, ans + arr[i][j+1],dp);
        }
        int b = 0;
        if (i + 1 >= 0 && i + 1 < arr.length && j + 1 >= 0 && j + 1 < arr[0].length) {
            b = goldmax(arr, i + 1, j + 1, ans + arr[i +1][j+1],dp);
        }
        int c = 0;
        if (i - 1 >= 0 && i - 1 < arr.length && j + 1 >= 0 && j + 1 < arr[0].length) {
            c = goldmax(arr, i - 1, j + 1, ans + arr[i-1][j+1],dp);
        }
        return dp[i][j]=arr[i][j] + Math.max(a, Math.max(b, c));
    }
    static int maxGold(int n, int m, int M[][])
    {
        // code here
         int ans = -1;
        int dp[][]=new int [n][m];
        for(int a[]:dp){
            Arrays.fill(a,-1);
        }
          for (int i = 0; i < n; i++) {
            ans = Math.max(ans, goldmax(M, i, 0, 0,dp));
        }

       return ans;
    }
} 