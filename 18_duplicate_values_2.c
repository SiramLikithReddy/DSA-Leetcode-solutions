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
struct Node*duplicate2(struct Node*head){
struct Node*temp=head;
while(temp!=NULL && temp->next!=NULL){
if(temp->data==temp->next->data){
temp=temp->next;
int count=1;
while(temp->next!=NULL && temp->data==temp->next->data){
count++;
struct Node*remove=temp->next;
temp->next=temp->next->next;
free(remove);
}
}
else{
temp=temp->next;
}
}
return head;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,3);
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
insertAtBeggining(&head,1);
insertAtBeggining(&head,1);
printf("Original List: ");
printList(head);
printf("Remastered List: ");
struct Node*result=duplicate2(head);
printList(result);
return 0;
}
