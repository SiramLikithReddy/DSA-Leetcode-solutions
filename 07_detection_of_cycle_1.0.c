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
void cycle(struct Node*head){
for(int i=0;i<=1000;i++){
if(i==1000){
if(head!=NULL){
printf("This is a cycle");
}
else{
printf("This is not a cycle");
}
}
else{
head=head->next;
}
}
}
int main(){
struct Node*head=NULL;
insertAtBeggining(&head,3);
insertAtBeggining(&head,2);
insertAtBeggining(&head,1);
head->next->next->next=head->next;
cycle(head);
return 0;
}

