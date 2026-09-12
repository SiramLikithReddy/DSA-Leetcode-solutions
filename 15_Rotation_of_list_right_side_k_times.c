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
struct Node*rotateList(struct Node*head,int k){
int n=0;
struct Node*temp=head;
while(temp!=NULL){
n++;
temp=temp->next;
}
temp=head;
int count=n-k;
struct Node*prevNode=NULL;
for(int i=0;i<count-1;i++){
temp=temp->next;
}
struct Node*start=temp->next;
for(int j=0;j<k-1;j++){
start=start->next;
}
struct Node*end=start;
start=temp->next;
temp->next=NULL;
temp=head;
end->next=temp;
head=start;
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
struct Node*result=rotateList(head,2);
printf("Remastered List: ");
while(result!=NULL){
printf("%d->",result->data);
result=result->next;
}
printf("NULL\n");
return 0;
}

