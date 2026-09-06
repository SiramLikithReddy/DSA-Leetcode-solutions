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
void reverseAList(struct Node**head){
    struct Node*prevNode=NULL;
    struct Node*current=*head;
    struct Node*ahead;
    while(current!=NULL){
        ahead=current->next;
        current->next=prevNode;
        prevNode=current;
        current=ahead;
    }
    *head=prevNode;
}
int main(){
    struct Node*head=NULL;
    insertAtBeggining(&head,5);
    insertAtBeggining(&head,4);
    insertAtBeggining(&head,3);
    insertAtBeggining(&head,2);
    insertAtBeggining(&head,1);
    printf("original List:\n");
    printList(head);
    printf("Reversed List:\n");
    reverseAList(&head);
    printList(head);
    return 0;
}
