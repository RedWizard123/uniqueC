#include<stdio.h>
#include<stdlib.h>
#include"TreeClass.h"
//Code of class Tree
int Tree::Count(){

}
//end


//code of class TreeNode
TreeNode::TreeNode(void* pv){
	TreeNode::pNode=this;
	TreeNode::value=pv;
	TreeNode::ChildList=new ChainList;
	//Node::ChildList
}
TreeNode::~TreeNode(){
	TreeNode::DeleteAllSub();
	free(TreeNode::value);
}
void TreeNode::DeleteAllSub(){
	int i=TreeNode::ChildList->Count();
	for(;i>0;i--){
		TreeNode::ChildList->Item(i)->DeleteAllSub();
		free(TreeNode::ChildList->Item(i));
		TreeNode::ChildList->Delete(i);

	}
}
void TreeNode::AddSubNode(class TreeNode* SubNode){
	SubNode->pParent=TreeNode::pNode;
	TreeNode::ChildList->Add(SubNode);
}
void TreeNode::InsertSubNode(int after,class TreeNode* SubNode){
	SubNode->pParent=TreeNode::pNode;
	TreeNode::ChildList->Insert(after,SubNode);
}

class TreeNode* TreeNode::Item(int Subindex){
	return(TreeNode::ChildList->Item(Subindex));
}

int TreeNode::CountSub(){
	return(TreeNode::ChildList->Count());
}

//end








//ChainList
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

class TreeNode* ChainList::Item(int index){
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

//end
