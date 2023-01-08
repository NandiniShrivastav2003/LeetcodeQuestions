//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	     int n=matrix.size();
	    for(int j=0;j<n;j++){
	        for(int k=0;k<n;k++){
	            if(matrix[j][k] == -1){
	            matrix[j][k]=INT_MAX;
	            }
	          
	        }
	    }
	   
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                if(matrix[j][i] != INT_MAX && matrix[i][k] != INT_MAX){
	                matrix[j][k]=min(matrix[j][k],matrix[j][i]+matrix[i][k]);
	                }
	            }
	        }
	    }
	    for(int j=0;j<n;j++){
	        for(int k=0;k<n;k++){
	            if(matrix[j][k] == INT_MAX){
	            matrix[j][k]=-1;
	            }
	          
	        }
	    }
	   
	    return ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends