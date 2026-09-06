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
    while(head!=NULL){
        printf("%d-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
struct Node*mergeList(struct Node*list1,struct Node*list2){
    struct Node*pack=malloc(sizeof(struct Node));
    struct Node*current=pack;
    
    while(list1!=NULL&&list2!=NULL){
        if(list1->data<list2->data){
            current->next=list1;
            current=current->next;
            list1=list1->next;
        }
        else{
            current->next=list2;
            current=current->next;
            list2=list2->next;
        }
    } 
    if(list1!=NULL){
        current->next=list1;
    }
    else{
        current->next=list2;
    }
    return pack->next;
}
int main(){
    struct Node*list1=NULL;
    insertAtBeggining(&list1,4);
    insertAtBeggining(&list1,2);
    insertAtBeggining(&list1,1);
    printf("List1:");
    printList(list1);
    struct Node*node1=malloc(sizeof(struct Node));
    node1->data=1;
    node1->next=NULL;
    struct Node*node2=malloc(sizeof(struct Node));
    node2->data=3;
    node2->next=NULL;
    struct Node*node3=malloc(sizeof(struct Node));
    node3->data=4;
    node3->next=NULL;
    node1->next=node2;
    node2->next=node3;
    printf("List2:");
    struct Node*list2=node1;
    struct Node*list2_backup=list2;
    while(list2_backup!=NULL){
        printf("%d-> ",list2_backup->data);
        list2_backup=list2_backup->next;
    }
    printf("NULL\n");
    struct Node *merged = mergeList(list1, list2);
printf("\nMerged List:\n");
printList(merged);
    return 0;
}
