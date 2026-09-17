#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node*next;
};

struct Stack{
    struct Node*top;
};

void push(struct Stack*stack, char value){
    struct Node*newnode = malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = stack->top;
    stack->top = newnode;
}

char pop(struct Stack*stack){
    if(stack->top == NULL) return '\0';
    
    char value = stack->top->data;
    struct Node*temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int isEmpty(struct Stack*stack){
    return stack->top == NULL;
}

int isValid(struct Stack*stack, char*str){
    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        
        if(c == '(' || c == '[' || c == '{'){
            push(stack, c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            char top = pop(stack);
            
            if((c == ')' && top == '(') || 
               (c == '}' && top == '{') || 
               (c == ']' && top == '[')){
                // Match good
            }
            else{
                return 0;
            }
        }
    }
    
    if(isEmpty(stack)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct Stack stack;
    stack.top = NULL;
    
    char check[] = "({[]})";
    
    int result = isValid(&stack, check);
    
    if(result == 1){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }
    
    return 0;
}
