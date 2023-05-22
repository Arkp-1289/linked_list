#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define nline "\n"
#define ll long long int

/******************************/
struct Node{
	int data;
	struct Node* next;
};

struct Node* tail=NULL;

struct Node* insert(struct Node* head,int d){
	// struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=d;
	temp->next=NULL;
	if (head==NULL){
		head=temp;
		tail=temp;
	} else{
	tail->next=temp;
	tail=temp;
     }
     return head;
  
}

void print(struct Node* head){
	struct Node* curr=head;
	while(curr){
		cout<<curr->data<<"->"<<" ";
		curr=curr->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
   struct Node* head1=NULL;
   struct Node* head2=NULL;
   int n1,n2;
   cin>>n1;


   while(n1--){
   	int t;
   	cin>>t;
   	// cout<<t;
   	head1=insert(head1,t);
  }  

   cin>>n2;
   while (n2--){
   	int t;
   	cin>>t;
   	head2=insert(head2,t);
   }
 print(head1);
 print(head2);
 vector<int>v1;
 vector<int>v2;
 struct Node* curr=head1;
 while(curr){
 	v1.eb(curr->data);
 	curr=curr->next;
 }
 struct Node* curr2=head2;
 while(curr2){
 	v2.eb(curr2->data);
 	curr2=curr2->next;
 }
 struct Node* res=NULL;
 struct Node* res_tail=NULL;
 int nv1=v1.size()-1,nv2=v2.size()-1,carry=0;
 while(nv1>=0 || nv2>=0 || carry!=0){
 	int sum=0;
 	if (nv1>=0){
 		sum+=v1[nv1];
 		nv1-=1;
 	}
 	if (nv2>=0){
 		sum+=v2[nv2];
        nv2-=1;
 	}
 	sum+=carry;
 	carry=sum/10;
 	sum=sum%10;
 	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
 	temp->data=sum;
 	temp->next=NULL;
    if (res==NULL){
    	res=temp;
    	res_tail=temp;
    } else{
    	res_tail->next=temp;
    	res_tail=temp;
    }

 }
 print(res);


  };





  INPUT: 
            5
            1 2 3 4 5
            5
            1 2 3 4 5
             
  OUTPUT:
            1-> 2-> 3-> 4-> 5-> NULL
            1-> 2-> 3-> 4-> 5-> NULL
            0-> 9-> 6-> 4-> 2-> NULL
