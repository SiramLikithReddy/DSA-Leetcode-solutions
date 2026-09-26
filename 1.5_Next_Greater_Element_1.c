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
stack.top=NULL;
int result[10];
int a[] = {1,2,1};
int n=3;
for(int i=0;i<n;i++){
int help=-1;
for(int j=i+1;j<n;j++){
if(a[i]<a[j]){
help=a[j];
break;
}
}
result[i]=help;
}
printf("[");
for(int k=0;k<n;k++){
printf("%d,",result[k]);
}
printf("]");
return 0;
}    
