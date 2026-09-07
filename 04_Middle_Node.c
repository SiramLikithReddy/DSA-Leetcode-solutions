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
int middle(struct Node*head){
    int n,middle;
    printf("Enter no.of nodes,u have in the linked list: ");
    scanf("%d",&n);
    if(n%2==0){
        middle=(n+2)/2;
    }
    else{
        middle=(n+1)/2;
    }
    for(int i=0;i<=middle-2;i++){
        head=head->next;
        if(i==middle-2){
            printf("Middle node;%d\n",head->data);
        }
        else{
            printf("\n");
        }
    }
    return 0;    
}
int main(){
    struct Node*head=NULL;
    insertAtBeggining(&head,5);
    insertAtBeggining(&head,4);
    insertAtBeggining(&head,3);
    insertAtBeggining(&head,2);
    insertAtBeggining(&head,1);
    printList(head);
    middle(head);
    return 0;
}
