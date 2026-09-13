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
struct Node*mergeLists(struct Node*list1,struct Node*list2,struct Node*list3){
struct Node*result1=malloc(sizeof(struct Node));
struct Node*current1=result1;
struct Node*temp1=list1;
struct Node*temp2=list2;
while(temp1!=NULL && temp2!=NULL){
if(temp1->data<temp2->data){
current1->next=temp1;
temp1=temp1->next;
current1=current1->next;
}else{
current1->next=temp2;
temp2=temp2->next;
current1=current1->next;
}
}
if(temp1!=NULL){
current1->next=temp1;
}else{
current1->next=temp2;
}
struct Node*result2=malloc(sizeof(struct Node));
struct Node*current2=result2;
struct Node*help=result1->next;
struct Node*temp3=list3;
while(help!=NULL && list3!=NULL){
if(help->data<list3->data){
current2->next=help;
help=help->next;
current2=current2->next;
}else{
current2->next=list3;
current2=current2->next;
list3=list3->next;
}
}
if(help!=NULL){
current2->next=help;
}else{
current2->next=list3;
}
return result2->next;
}
int main(){
struct Node*list1=NULL;
insertAtBeggining(&list1,5);
insertAtBeggining(&list1,4);
insertAtBeggining(&list1,1);
struct Node*list2=NULL;
insertAtBeggining(&list2,4);
insertAtBeggining(&list2,3);
insertAtBeggining(&list2,1);
struct Node*list3=NULL;
insertAtBeggining(&list3,6);
insertAtBeggining(&list3,2);
printf("LIST 1:\n");
printList(list1);
printf("LIST 2:\n");
printList(list2);
printf("LIST 3:\n");
printList(list3);
printf("SORTED LIST: \n");
struct Node*final=mergeLists(list1,list2,list3);
printList(final);
return 0;
}
