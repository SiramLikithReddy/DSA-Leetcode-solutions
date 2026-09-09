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
int detection(struct Node*head){
struct Node*fast=head;
struct Node*slow=head;
while(fast!=NULL && slow!=NULL && fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
if(slow==fast){
slow=head;
while(slow!=fast){
slow=slow->next;
fast=fast->next;
}
printf("Cycle starts at %d\n",slow->data);
return 1;
}
}
printf("No cycle for this linked list");
return 0;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
head->next->next->next=head->next;
detection(head);
return 0;
}
