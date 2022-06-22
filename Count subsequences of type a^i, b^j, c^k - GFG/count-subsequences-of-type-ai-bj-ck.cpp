// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string s) {
         const unsigned int mod = 1e9+7;
        //code here
        int aCount=0;
        int bCount=0;
        int cCount=0;
         for (unsigned int i = 0; i < s.size(); i++) {
            if(s[i] == 'a'){
            aCount=((2*aCount)%mod+1)%mod;
            }
            else if( s[i] == 'b'){
                bCount=((2*bCount)%mod+aCount)%mod;
            }
            else {
                cCount=((2*cCount)%mod+bCount)%mod;
                
            }
        }
        return cCount;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends