#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node*next;
int save;
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
int n=0;
int result[10];
char *arr[] = {"()", "([)]", "(())", "[(", "]", NULL};
for(int i = 0; arr[i]!= NULL; i++){
n++;
}
for(int i=0;i<n;i++){
stack.top=NULL;
int wait=1;
char *str=arr[i];
for(int j=0;str[j]!='\0';j++){
if(str[j]=='('||str[j]=='{'||str[j]=='['){
push(&stack,(int)str[j]);
}else if(str[j]==')'||str[j]=='}'||str[j]==']'){
char top=pop(&stack);
if(str[j]==')' && top=='(' || str[j]=='}' && top=='{' || str[j]==']' && top=='['){
wait=1;
}else{
wait=0;
break;
}
}
}
if(stack.top!=NULL) wait=0;
result[i]=wait;
}
printf("[");
for(int k=0;k<n;k++){
printf("%d",result[k]);
}
printf("]");
return 0;
}
