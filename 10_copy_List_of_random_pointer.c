#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
struct Node*random;
};
struct Node*copyListWithRandomPointer(struct Node*head){
int count=0;
struct Node*original[100];
struct Node*copied[100];
struct Node*temp=head;
while(temp!=NULL){
original[count]=temp;
temp=temp->next;
count++;
}
for(int i=0;i<count;i++){
struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=original[i]->data;
newnode->next=NULL;
newnode->random=NULL;
copied[i]=newnode;
}
for(int i=0;i<count-1;i++){
copied[i]->next=copied[i+1];
}
for(int i=0;i<count;i++){
if(original[i]->random==NULL){
copied[i]->random=NULL;
}
else{
for(int j=0;j<count;j++){
if(original[j]==original[i]->random){
copied[i]->random=copied[j];
break;
}
}
}
}
return copied[0];
}
int main(){
struct Node*a=malloc(sizeof(struct Node));
struct Node*b=malloc(sizeof(struct Node));
struct Node*c=malloc(sizeof(struct Node));
a->data=1;a->next=b;
b->data=2;b->next=c;
c->data=3;c->next=NULL;
a->random=c;
b->random=a;
c->random=NULL;
struct Node*copiedNode=copyListWithRandomPointer(a);
printf("Original List\n");
struct Node*temp=a;
while(temp!=NULL){
printf("Data:%d,random:%d\n",temp->data,temp->random!=NULL?temp->random->data:-1);
temp=temp->next;
}
printf("Copied List\n");
temp=copiedNode;
while(temp!=NULL){
printf("Data:%d,random:%d\n",temp->data,temp->random!=NULL?temp->random->data:-1);
temp=temp->next;
}
return 0;
}




    
