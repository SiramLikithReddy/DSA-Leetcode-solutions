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
printf("List\n");
while(head!=NULL){
printf("%d-> ",head->data);
head=head->next;
}
printf("NULL\n");
}
void deleteSpecific(struct Node*prevNode){
if(prevNode==NULL||prevNode->next==NULL)return;
struct Node*temp=prevNode->next;
prevNode->next=temp->next;
free(temp);
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,2);
insertAtBeggining(&head,3);
insertAtBeggining(&head,4);
insertAtBeggining(&head,1);
printList(head);
printf("After deletion:");
deleteSpecific(head->next);
printList(head);
return 0;
}

