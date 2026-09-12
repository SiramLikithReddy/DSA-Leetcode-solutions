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
struct Node*h=head;
while(h!=NULL){
printf("%d-> ",h->data);
h=h->next;
}
printf("NULL\n");
}
struct Node*KReverse(struct Node*head,int k){
int n=0;
struct Node*temp=head;
while(temp!=NULL){
n++;
temp=temp->next;
}
int groups=n/k;
struct Node*current=head;
struct Node*prevEndGroup=NULL;
for(int g=0;g<groups;g++){
struct Node*groupEnd=current;
for(int i=0;i<k-1;i++){
groupEnd=groupEnd->next;
}
struct Node*nextGroupStart=groupEnd->next;
struct Node*prevNode=NULL;
struct Node*node=current;
struct Node*ahead;
for(int i=0;i<k;i++){
ahead=node->next;
node->next=prevNode;
prevNode=node;
node=ahead;
}
if(g==0){
head=prevNode;
}else{
prevEndGroup->next=prevNode;
}
prevEndGroup=current;
current=nextGroupStart;
}
return head;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,6);
insertAtBeggining(&head,5);
insertAtBeggining(&head,4);
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
printList(head);
struct Node*result=KReverse(head,2);
while(result!=NULL){
printf("%d-> ",result->data);
result=result->next;
}
printf("NULL\n");
return 0;
}
