#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
};
struct Stack{
struct Node*top;
};
void push(struct Stack*stack,int value){
struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=value;
newnode->next=stack->top;
stack->top=newnode;
}
int pop(struct Stack*stack){
if(stack->top==NULL) return 0;
int value=stack->top->data;
struct Node*temp=stack->top;
stack->top=stack->top->next;
free(temp);
return value;
}
int main(){
struct Stack stack;
stack.top=NULL;
char a[]="abbaca";
int position=0;
for(int i=0;a[i]!='\0';i++){
char b=a[i];
if(stack.top==NULL){
push(&stack,b);
}
else if(stack.top->data==b){
pop(&stack);
}
else{
push(&stack,b);
}
}
char result[100];
int g=0;
struct Node*temp=stack.top;
while(temp!=NULL){
result[g++]=temp->data;
temp=temp->next;
}
for(int k=g-1;k>=0;k--){
printf("%c",result[k]);
}
return 0;
}
