//{ Driver Code Starts
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node{
    int data;
    Node *left,*right;
    
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"\n";
    }

	return 0;
}

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}

// } Driver Code Ends


void inorder(Node *root, vector<int>&res){
    if(root == NULL){
        return ;
    }
    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);
}
int  merge( int arr[],  int temp[],int left,int mid,int right ){
      int i,j,k;
      int inv_count=0;
      i=left;
      j=mid;
      k=left;
      while(i<=mid-1 && j<=right){
          if(arr[i]<=arr[j]){
              temp[k++]=arr[i++];
          }
          else{
              temp[k++]=arr[j++];
              inv_count+=(mid-i);
          }
      }
      while(i<=mid-1){
          temp[k++]=arr[i++];
      }
      while(j<=right){
          temp[k++]=arr[j++];
      }
      for(i=left;i<=right;i++){
          arr[i]=temp[i];
      }
      return inv_count;
  }
int mergeSort(int arr[], int temp[],int  i, int j){
      int mid,inv_count=0;
      if(j>i){
          mid=(j+i)/2;
          inv_count+=mergeSort(arr,temp,i,mid);
          inv_count+=mergeSort(arr,temp,mid+1,j);
          inv_count+=merge(arr,temp,i,mid+1,j);
      }
      return inv_count;
  }
int pairsViolatingBST(Node *root,int n){
    vector<int>res;
          inorder(root,res);
         int temp[res.size()];
         int arr[res.size()];
         for(int i=0;i<res.size();i++){
             arr[i]=res[i];
         }
         int size=res.size();
       return mergeSort(arr,temp,0,size-1);
}
