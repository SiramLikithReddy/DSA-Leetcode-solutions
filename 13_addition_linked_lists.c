#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
};
void insertAtBeggining(struct Node**head,int value){
struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=value;
newnode->next=*head;
*head=newnode;
}
void printList(struct Node*head){
while(head!=NULL){
printf("%d -> ",head->data);
head=head->next;
}
printf("NULL\n");
}
struct Node*add(struct Node*list1,struct Node*list2){
struct Node*result=NULL;
struct Node*temp1=list1;
struct Node*temp2=list2;
int carry=0;
while(temp1!=NULL || temp2!=NULL || carry!=0){
int digit1=temp1!=NULL?temp1->data:0;
int digit2=temp2!=NULL?temp2->data:0;
int sum=digit1+digit2+carry;
int digit=sum%10;
carry=digit/10;
struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=digit;
newnode->next=result;
result=newnode;
if(temp1!=NULL)temp1=temp1->next;
if(temp2!=NULL)temp2=temp2->next;
}
struct Node*prevNode=NULL;
struct Node*current=result;
struct Node*ahead;
while(current!=NULL){
ahead=current->next;
current->next=prevNode;
prevNode=current;
current=ahead;
}
return prevNode;
}
int main(){
struct Node*list1=NULL;
insertAtBeggining(&list1,5);
insertAtBeggining(&list1,4);
insertAtBeggining(&list1,6);
struct Node*node1=malloc(sizeof(struct Node));
struct Node*node2=malloc(sizeof(struct Node));
struct Node*node3=malloc(sizeof(struct Node));
node1->data=1,node1->next=node2;
node2->data=2,node2->next=node3;
node3->data=3,node3->next=NULL;
struct Node*list2=node1;
printList(list1);
printList(list2);
struct Node*resultPrint=add(list1,list2);
while(resultPrint!=NULL){
printf("%d-> ",resultPrint->data);
resultPrint=resultPrint->next;
}
printf("NULL\n");
return 0;
}
    
