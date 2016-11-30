#include <stdio.h>
#include <stdlib.h>
typedef void* ElementType;
struct Node{
    ElementType value;
    struct Node* next;
};

void add(struct Node* l,void* value){
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=(struct Node *)malloc(sizeof(struct Node));
    l->next->value=value;
    l->next->next=NULL;
};
ElementType item(struct Node* l,int index){
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
void insert(struct Node* l,int insertafter,ElementType value){
    insertafter++;int i;
    for(i=0;i<insertafter&&l->next!=NULL;i++){
        l=l->next;
    }
    struct Node* a=l->next;
    l->next=(struct Node*)malloc(sizeof(struct Node));
    l->next->value=value;
    l->next->next=a;
}





void main (){
    int i=1;
    struct Node* header=(struct Node*)malloc(sizeof(struct Node));
    header->value=0;
    header->next=NULL;
    for(i=0;i<10;i++){
        int * p=(int *)malloc((i+1)*sizeof(int));
        *p=i;
        add(header,p);

    }
    for(i=0;i<length(header);i++){
        printf("%d\t",*(int *)item(header,i));
    }

}
