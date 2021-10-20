#include <bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(){
          int val =0;
          next=NULL;
      }
      ListNode(int x) {
           val= x;
          next=NULL;
     }
      ListNode(int x, ListNode *n){
          val= x;
          next=n;
      }
  };
 
long long int getnum(ListNode* l){
    long long int res=0;
    long long int n=1;
    while(l!=NULL){
        res= res+ n * (l->val);
        n*=10;
        l=l->next;
    }
    return res;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        long long int num1=getnum(l1);
        long long int num2=getnum(l2);
        long long int n=num1+num2;
        cout<<"n1= "<<num1<<endl;
        cout<<"n2= "<<num2<<endl;
        cout<<"sum= "<<n<<endl;
        ListNode* ans=new ListNode(n%10);
        ListNode* res=ans;
        n/=10;
        while(n){
            ListNode* temp=new ListNode(n%10);
            ans->next=temp;
            ans=ans->next;
            n/=10;
        }
        return res;
    }


int main()
{
    ListNode* node=new ListNode(9);
    ListNode* node2=new ListNode(1);
    node2->next=new ListNode(9);
    node2->next->next=new ListNode(9);
    node2->next->next->next=new ListNode(9);
    node2->next->next->next->next=new ListNode(9);
    node2->next->next->next->next->next=new ListNode(9);
    node2->next->next->next->next->next->next=new ListNode(9);
    node2->next->next->next->next->next->next->next=new ListNode(9);
    node2->next->next->next->next->next->next->next->next=new ListNode(9);
    node2->next->next->next->next->next->next->next->next->next=new ListNode(9);

    ListNode* ans= addTwoNumbers(node, node2);
    while(node2!=NULL){
        cout<<node2->val<<" ";
        node2=node2->next;
    }
    cout<<endl;
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
/*
test case:
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1  
8 5 1
output:
7 8
8 5
4 3
1 2
3 5
2 3
6 7
cost is: 27
*/
 