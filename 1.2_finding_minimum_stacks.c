#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
int min_at_that_point;
struct Node*next;
};
struct Stack{
struct Node*top;
};
void push(struct Stack*stack, int value){
struct Node*newnode=malloc(sizeof(struct Node));
newnode->data=value;
if(stack->top==NULL){
newnode->min_at_that_point=value;
}else{
int prev_min=stack->top->min_at_that_point;
newnode->min_at_that_point=(value<prev_min)?value:prev_min;
}
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
int isMin(struct Stack*stack){
if(stack->top==NULL) return -1;
return stack->top->min_at_that_point;
}
int isEmpty(struct Stack*stack){
return stack->top==NULL;
}
int main(){
struct Stack stack;
stack.top=NULL;
push(&stack,1);
push(&stack,2);
push(&stack,3);
push(&stack,4);
push(&stack,5);
printf("MINIMUM :%d" ,isMin(&stack));
return 0;
}


