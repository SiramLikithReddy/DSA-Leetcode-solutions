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
printf("%d-> ",head->data);
head=head->next;
}
printf("NULL\n");
}
struct Node*arrange(struct Node*head,int x){
struct Node*chain1=malloc(sizeof(struct Node));
struct Node*help1=chain1;
struct Node*chain2=malloc(sizeof(struct Node));
struct Node*help2=chain2;
struct Node*temp=head;
while(temp!=NULL){
if(temp->data<x){
help1->next=temp;
help1=help1->next;
temp=temp->next;
}else{
help2->next=temp;
help2=help2->next;
temp=temp->next;
}
}
help2->next=NULL;
help1->next=chain2->next;
return chain1->next;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,2);
insertAtBeggining(&head,5);
insertAtBeggining(&head,2);
insertAtBeggining(&head,3);
insertAtBeggining(&head,4);
insertAtBeggining(&head,1);
printf("Original List: \n");
printList(head);
printf("Remastered List:\n ");
struct Node*final=arrange(head,3);
printList(final);
return 0;
}


    
