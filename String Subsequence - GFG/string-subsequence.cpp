//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int count(string a,string b,int m,int n){
    if( m == 0 && n == 0 || n == 0){
        return 1;
    }
    if(m == 0){
        return 0;
    }
    if(a[m-1] == b[n-1]){
        return count(a,b,m-1,n-1)+count(a,b,m-1,n);
    }
    else{
        return count(a,b,m-1,n);
    }
    
}
    int countWays(string S1, string S2){
        // code here
       return  count(S1,S2,S1.size(),S2.size());
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends