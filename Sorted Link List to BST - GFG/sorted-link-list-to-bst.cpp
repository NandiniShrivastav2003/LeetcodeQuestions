// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends

class Solution{
  public:
  TNode* toBST(LNode *head,LNode *tail){
      if(head == tail){
          return NULL;
      }
      LNode *slow=head;
      LNode *fast=head;
      while(fast != tail && fast->next != tail){
          fast=fast->next->next;
          slow=slow->next;
      }
      TNode *root=new TNode(slow->data);
      root->left=toBST(head,slow);
      root->right=toBST(slow->next,tail);
      return root;
  }
    TNode* sortedListToBST(LNode *head) {
    if(head == NULL){return NULL;}
    return toBST(head,NULL);
    
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends