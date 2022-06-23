// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	 
    int lis[n];
    lis[0]=a[0];
    for(int i=1;i<n;i++){
        lis[i]=a[i];
        int res=lis[i];
        for(int j=0;j<i;j++){
            int temp=a[i];
            if(a[j] < a[i]){
            res=max(res,temp+lis[j]);
            }
        }
        lis[i]=res;
        
    }
    int res=lis[0];
    for(int i=1;i<n;i++){
        res=max(res,lis[i]);
    }
    return res;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends