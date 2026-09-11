#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
struct Node*child;
};
struct Node*flatten(struct Node*head){
struct Node*current=head;
while(current!=NULL){
if(current->child==NULL){
current=current->next;
}
else{
struct Node*temp=current->next;
current->next=current->child;
current->child=NULL;
struct Node*tail=current->next;
while(tail->next!=NULL){
tail=tail->next;
}
tail->next=temp;
current=current->next;
}
}
current=head;
return head;
}
int main(){
struct Node*node1=malloc(sizeof(struct Node));
node1->data=1;
node1->next=NULL;
struct Node*node2=malloc(sizeof(struct Node));
node2->data=2;
node2->next=NULL;
struct Node*node3=malloc(sizeof(struct Node));
node3->data=3;
node3->next=NULL;
struct Node*node4=malloc(sizeof(struct Node));
node4->data=4;
node4->next=NULL;
struct Node*node5=malloc(sizeof(struct Node));
node5->data=5;
node5->next=NULL;
struct Node*node6=malloc(sizeof(struct Node));
node6->data=6;
node6->next=NULL;
struct Node*node7=malloc(sizeof(struct Node));
node7->data=7;
node7->next=NULL;
node1->next=node2;
node2->next=node3;
node3->next=node4;
node2->child=node5;
node5->next=node6;
node5->child=node7;
struct Node*print=flatten(node1);
while(print!=NULL){
printf("%d-> ",print->data);
print=print->next;
}
printf("NULL\n");
return 0;
}
