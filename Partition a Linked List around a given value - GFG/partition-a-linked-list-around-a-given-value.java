// { Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.io.*;
import java.lang.*;

class Node {
    int data;
    Node next;
    Node(int key) {
        data = key;
        next = null;
    }
}

class Partition {
    static Node head;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;
            for (int i = 1; i < n; i++) {
                int a = sc.nextInt();
                // addToTheLast(new Node(a));
                tail.next = new Node(a);
                tail = tail.next;
            }

            int k = sc.nextInt();
            Solution ob = new Solution();
            Node res = ob.partition(head, k);
            printList(res);
            System.out.println();
        }
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
}// } Driver Code Ends



class Solution {
    public static Node partition(Node head, int x) {
      Node p1=new Node(-1);
      ArrayList<Node>mid=new ArrayList<Node>();
        Node a=p1;
   Node p2=new Node(-1);
        Node b=p2;
      
        while(head != null){
            if(head.data < x){
               p1.next=head;
               p1=p1.next;
            }
            else if(head.data == x){
                mid.add(head);
            }
            else{
                p2.next=head;
                p2=p2.next;
            }
            head=head.next;
        }
        for (int i = 0; i < mid.size(); i++){
           p1.next=mid.get(i) ;
           p1=p1.next;
        }
        p1.next=b.next;
        p2.next=null;
        return a.next;
    }
}