#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
int cycle(struct Node*head){
struct Node*slow=head;
struct Node*fast=head;
while(slow!=NULL && fast!=NULL && fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
if(slow==fast){
return 1;
}
}
return 0;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
head->next->next->next=head->next;
int result=cycle(head);
if(result==1){
printf("yes,it's cycle");
}
else{
printf("No,it's not a cycle");
}
return 0;
}

