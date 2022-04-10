// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    vector<int>minStack;
    stack<int> s;
     public:
  int getMin(){
      if(minStack.size() > 0){
          return minStack[minStack.size()-1]; 
      }
      return -1;
           
       }
int pop(){
    int res=-1;
    if(!s.empty()){
       res= s.top();
      s.pop();
    }
    if(minStack.size() >0){
       minStack.pop_back();
    }
return res;
       }
 void push(int x){
         s.push(x);
         if(minStack.size() == 0){
              minStack.push_back(x);
         }
         else{
         minEle=min(minStack[minStack.size()-1],x);
         minStack.push_back(minEle);
         }
       }
};

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends