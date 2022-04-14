// { Driver Code Starts
//Initial Template for Java

import java.util.*;
class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}
class Zeroes{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            Node head=null;
            while(n-->0){
                int a=sc.nextInt();
                if(head==null){
                    head=new Node(a);
                }
                else{
                    Node temp=new Node(a);
                    temp.next=head;
                    head=temp;
                }
            }
            GfG g=new GfG();
            head = g.moveZeroes(head);
            while(head!=null){
                System.out.print(head.data+" ");
                head=head.next;
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java

/*
class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}
*/

class GfG{
    public Node moveZeroes(Node head){
       Node  p1=new Node(-1);
        Node p2=new Node(-1);
      
       Node ans1=p1;
      
       Node ans2=p2;
       Node temp=head;
       while(temp != null){
           if(temp.data == 0){
               p1.next=temp;
               p1=p1.next;
           }
           else{
               p2.next=temp;
               p2=p2.next;
           }
           temp=temp.next;
       }
       p2.next=null;
    p1.next=ans2.next;
    return ans1.next;
        
    }
}