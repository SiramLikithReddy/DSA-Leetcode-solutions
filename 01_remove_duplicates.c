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
    printf("List:");
    while(head!=NULL){
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void deleteDuplicate(struct Node*current){
    while(current!=NULL&&current->next!=NULL){
        if(current->data==current->next->data){
            struct Node*temp=current->next;
            current->next=temp->next;
            free(temp);
        }
        else{
            current=current->next;
        }
    }
}
int main(){
    struct Node*head=NULL;
    insertAtBeggining(&head,2);
    insertAtBeggining(&head,1);
    insertAtBeggining(&head,1);
    printf("original List:\n");
    printList(head);
    deleteDuplicate(head);
    printf("Duplicate List:\n");
    printList(head);
    return 0;
}
