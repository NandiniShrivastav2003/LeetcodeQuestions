// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    int  ans(int nums[],int  dp[],int n){
       
        for(int i=0;i<n;i++){
            if(i < 0){
            return 0;
        }
           
            dp[i]=max((i-2 < 0 ? 0 : dp[i-2])+nums[i],(i-1 < 0 ? 0: dp[i-1]));
        }
        return dp[n-1];
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
       return  ans(arr,dp,n);
    }
};
 
    
// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends