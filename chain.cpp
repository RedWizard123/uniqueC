#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node{
    int value;
    struct Node* next;
};
void add(struct Node* l,int value){
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=(struct Node *)malloc(sizeof(struct Node *));
    l->next->value=value;
    l->next->next=NULL;
};
int item(struct Node* l,int index){
    index++;
    int i;
    for(i=0;i<index&&l->next!=NULL;i++){
        l=l->next;
    }
    return(l->value);
}
int length(struct Node* l){
    int n=0;
    while(l->next!=NULL){
        l=l->next;
        n++;
    }
    return(n);
}
void insert(struct Node* l,int insertafter,int value){
    insertafter++;
    int i;
    for(i=0;i<insertafter&&l->next!=NULL;i++){
        l=l->next;
    }
    struct Node* a=l->next;
    l->next=(struct Node*)malloc(sizeof(struct Node*));
    l->next->value=value;
    l->next->next=a;
}
int main (){
    int i=1;
    struct Node* header=(struct Node*)malloc(sizeof(struct Node*));
    header->value=0;
    header->next=NULL;
    for(i=0;i<10;i++){
        add(header,i);
    }
    printf("\nlength:%d",length(header));
    printf("\nlength:%d\n",length(header));
    for(i=0;i<12;i++){
        printf("%d\t",item(header,i));
    }
	

}
