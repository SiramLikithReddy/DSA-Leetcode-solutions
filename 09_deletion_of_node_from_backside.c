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
printf("List:\n");
while(head!=NULL){
printf("%d->  ",head->data);
head=head->next;
}
printf("NULL\n");
}
void deletionFromEnd(struct Node*head){
int n,count=0;
printf("Enter the positin of the node that u want to delete from backside\n");
scanf("%d",&n);
struct Node*countptr=head;
while(countptr!=NULL){
count++;
countptr=countptr->next;
}
int nodetodelete=count-n;
struct Node*temp=head;
for(int i=0;i<nodetodelete-1;i++){
temp=temp->next;
}
struct Node*nodeToDelete=temp->next;
temp->next=temp->next->next;
free(nodeToDelete);
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,4);
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
printList(head);
deletionFromEnd(head);
printf("After deletion:");
printList(head);
return 0;
}
