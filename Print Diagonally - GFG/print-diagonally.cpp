//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		 vector<int>ans;

 for(int sum = 0; sum<N*2-1; sum++){

     int xlim = sum >= N ? N : sum+1;

     int yind = sum >= N ? N-1 : sum;

     int xind = sum >= N ? sum-N+1 : 0;

     for(; xind<xlim; xind++){

         ans.push_back(A[xind][yind]);

         yind--;

     }

 }

 return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends