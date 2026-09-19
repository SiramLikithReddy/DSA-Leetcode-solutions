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
char *array[]={"5","2","+","C","D"};
int n=5;
for(int i=0;i<n;i++){
char *str=array[i];
if(str[0]=='+'){
int a=pop(&stack);
int b=pop(&stack);
push(&stack,b);
push(&stack,a);
int sum=a+b;
push(&stack,sum);
}
else if(str[0]=='C'){
pop(&stack);
}
else if(str[0]=='D'){
int a=pop(&stack);
int b=(a*2);
push(&stack,a);
push(&stack,b);
}
else{
int num=atoi(str);
push(&stack,num);
}
}
int total=0;
struct Node*temp=stack.top;
while(temp!=NULL){
total+=temp->data;
temp=temp->next;
}
printf("Total of those numbers in the list:%d\n",total);
return 0;
}
