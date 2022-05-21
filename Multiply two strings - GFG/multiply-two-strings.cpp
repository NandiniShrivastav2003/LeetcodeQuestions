// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        if(s1 == "0" || s2 == "0"){return "0";}
        char sig;
        if((s1.at(0) == '-' || s2.at(0) == '-') &&
        (s1.at(0) != '-' || s2.at(0) != '-' )){
            sig='-';
        }
        if(s1.at(0) == '-'){
            s1=s1.substr(1);
           
        }
        if(s2.at(0) == '-'){
            s2=s2.substr(1);
        
        }
      int size=s1.size()+s2.size();
     vector<int>arr(size,0);
      int v=0;
     
        int cal=0;
      for(int i=s2.size()-1;i>=0;i--){
           int carry=0;
          int n=s2[i]-'0';
          int temp=size-1-v;
          for(int j=s1.size()-1;j>=0;j--){
              int val=n*(s1[j]-'0');
              int sum=val+carry+arr[temp];
              arr[temp]=sum%10;
              carry=sum/10;
             
              temp--;
          }
          if(carry>0){
              arr[temp]+=carry;
          }
          v++;
      }
      int j;
      for(int i=0;i<size;i++){
          while(arr[i] == 0){
              i++;
          }
          j=i;
          break;
      }
      string ans="";
      if(sig == '-'){
          ans+=sig;
      }
      for(int i=j;i<size;i++){
    ans+=to_string(arr[i]);
      }
      
      return ans;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends