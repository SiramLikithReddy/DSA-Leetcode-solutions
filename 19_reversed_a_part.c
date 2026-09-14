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
struct Node*arrange(struct Node*head,int left,int right){
struct Node*temp=head;
for(int i=0;i<left-1;i++){
temp=temp->next;
}
struct Node*leftone=temp;
temp=head;
for(int x=0;x<right-1;x++){
temp=temp->next;
}
struct Node*rightone=temp;
temp=head;
struct Node*help=rightone->next;
rightone->next=NULL;
struct Node*prevNode=NULL;
struct Node*current=leftone;
struct Node*ahead;
while(current!=NULL){
ahead=current->next;
current->next=prevNode;
prevNode=current;
current=ahead;
}
temp->next=prevNode;
leftone->next=help;
return head;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,5);
insertAtBeggining(&head,4);
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
printf("Original List: ");
printList(head);
printf("Remastered List: ");
struct Node*result=arrange(head,2,4);
printList(result);
return 0;
}
