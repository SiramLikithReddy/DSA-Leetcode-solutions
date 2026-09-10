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
printf("List: \n");
while(head!=NULL){
printf("%d-> ",head->data);
head=head->next;
}
printf("NULL\n");
}
struct Node*reorder(struct Node**head){
int n=0;
int middle;
struct Node*middleNode;
struct Node*temp=*head;
while(temp!=NULL){
n++;
temp=temp->next;
}
middle=(n+1)/2;
temp=*head;
for(int i=0;i<=middle-2;i++){
temp=temp->next;
if(i==middle-2){
middleNode=temp;
}
}
struct Node*prevNode=NULL;
struct Node*current=middleNode->next;
struct Node*ahead;
while(current!=NULL){
ahead=current->next;
current->next=prevNode;
prevNode=current;
current=ahead;
}
middleNode->next=NULL;
struct Node*ptr2=prevNode;
struct Node*ptr1=*head;
struct Node*pptr1=ptr1->next;
struct Node*pptr2=ptr2->next;
while(ptr1!=NULL && ptr2!=NULL){
struct Node*temp1=ptr1->next;
struct Node*temp2=ptr2->next;
ptr1->next=ptr2;
ptr2->next=temp1;
ptr1 = temp1;
ptr2 = temp2;
}
return *head;
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,4);
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
printf("Original List: ");
printList(head);
struct Node*new=reorder(&head);
printf("Reordered List: ");
while(new!=NULL){
printf("%d-> ",new->data);
new=new->next;
}
printf("NULL\n");
return 0;
}

    
