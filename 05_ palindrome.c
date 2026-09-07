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
printf("List: ");
while(head!=NULL){
printf("%d-> ",head->data);
head=head->next;
}
printf("NULL\n");
}
void palindrome(struct Node**head){
int n,middle;
struct Node*middleNode;
printf("Enter no.of nodes from the linked list:");
scanf("%d",&n);
if(n%2==0){
middle=(n+2)/2;
}else{
middle=(n+1)/2;
}
struct Node*temp=*head;
for(int i=0;i<=middle-2;i++){
temp=temp->next;
if(i==middle-2){
middleNode=temp;
}
else{
printf("\n");
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
temp=*head;
//comparing two half linked list to confirm it is palindrome.
while(prevNode!=NULL){
if(temp->data!=prevNode->data){
printf("No,it's not palindrome");
return;
}
temp=temp->next;
prevNode=prevNode->next;
}
printf("yes,it's palindrome");
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,1);
insertAtBeggining(&head,2);
insertAtBeggining(&head,3);
insertAtBeggining(&head,4);
printList(head);
palindrome(&head);
return 0;
}



