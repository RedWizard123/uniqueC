#include <stdio.h>
#include <stdlib.h>
#include "TreeChainList.h"
#include "TreeClass.h"
ChainList::ChainList(){
    ChainList::header=(struct Node*)malloc(sizeof(struct Node*));
    ChainList::header->next=NULL;
    ChainList::header->value=NULL;
}
ChainList::~ChainList(){
    free(header);
}
void ChainList::Add(class TreeNode* pv){
    struct Node* l=ChainList::header;
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=(struct Node *)malloc(sizeof(struct Node *));
    l->next->value=pv;
    l->next->next=NULL;
}

void* ChainList::Item(int index){
    index++;
    struct Node* l=header;
    int i;
    for(i=0;i<index&&l->next!=NULL;i++){
        l=l->next;
    }
    return(l->value);
}
int ChainList::Count(){
    struct Node* l=header;
    int n=0;
    while(l->next!=NULL){
        l=l->next;
        n++;
    }
    return(n);
}

void ChainList::Insert(int after,class TreeNode* pv){
    struct Node* l=header;
    after++;
    int i;
    for(i=0;i<after&&l->next!=NULL;i++){
        l=l->next;
    }
    struct Node* a=l->next;
    l->next=(struct Node*)malloc(sizeof(struct Node));
    l->next->value=pv;
    l->next->next=a;
}
void ChainList::Delete(int position){
    if(ChainList::Count()!=0){
        struct Node* l=header;
        int i;
        for(i=0;i<position&&l->next->next!=NULL;i++){
            l=l->next;
        }
        struct Node* a=l->next->next;
        free(l->next);
        l->next=a;
    }
}
