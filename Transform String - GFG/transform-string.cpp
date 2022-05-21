// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.size() != B.size()){return -1;}
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<A.size();i++){
            m1[A[i]]++;
            m2[B[i]]++;
        }
        for(int i=0;i<A.size();i++){
            if(m1[A[i]] != m2[A[i]]){return -1;}
        }
        int count=0;
        int j=B.size()-1;
        for(int i=A.size()-1;i>=0;i--){
            if(A[i] == B[j]){ j--;continue;}
           else{
                count++;
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends