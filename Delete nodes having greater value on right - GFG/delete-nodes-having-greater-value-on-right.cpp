//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        while(curr != NULL){
            Node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    Node *removeGreater(Node *head,int x){
        Node *newhead=head->next;
        Node *temp=head;
        while(newhead != NULL){
            x=max(x,newhead->data);
            if(newhead->data < x){
                newhead=newhead->next;
                
            }
            else{
               temp->next=newhead;
               newhead=newhead->next;
               temp=temp->next;
            }
           
            
        }
        temp->next=newhead;
        return head;
    }
    Node *compute(Node *head)
    {
        Node *temp=reverse(head);
        if(temp == NULL && temp->next == NULL){
            return temp;
        }
        
        head=removeGreater(temp,temp->data);
       
      return   reverse(head);
         
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends