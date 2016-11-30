#include<stdio.h>
#include<stdlib.h>
#include"TreeClass.h"
int main(){
	int* c=(int*)malloc(sizeof(int));
	*c=15;
	TreeNode* root=new TreeNode(c);
	/*
	int i,j;
	for(i=0;i<10;i++){
		int* a=(int*)malloc(sizeof(int));
		*a=i;
		TreeNode* t=new TreeNode(a);
		root->AddSubNode(t);
		for(j=0;j<10-i;j++){
			root->Item(i)->AddSubNode(t);
		}
		//printf("%d\n",root->Item(i)->CountSub());
		printf("%d\n",*(int *)(root->Item(i)->value));
	}
	printf("%d\n",root->CountSub());

	//root->ChildList->Item(1)->ChildList->Item(0);
	printf("%d\n",*(int *)(root->value));
	printf("%d\n",root->CountSub());
	*/

	root->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	root->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	root->Item(0)->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	root->Item(0)->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	root->Item(0)->Item(0)->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	root->Item(0)->Item(0)->AddSubNode(new TreeNode((int*)malloc(sizeof(int))));
	int i,j;
	for(i=0;i<10;i++){
		int* a=(int*)malloc(sizeof(int));
		*a=i;

		TreeNode* t=new TreeNode(a);
		root->Item(0)->Item(1)->AddSubNode(t);
		for(j=0;j<100;j++){
			int* a=(int*)malloc(sizeof(int));
			*a=i;
			TreeNode* t=new TreeNode(a);
			root->Item(0)->Item(1)->Item(i)->AddSubNode(t);
		}
	}
	//printf("%d\n",*(int *)(root->Item(0)->Item(1)->Item(998)->value));
	
	root->Item(0)->Item(1)->DeleteAllSub();
	printf("%d\n",root->Item(0)->Item(1)->CountSub());
	free(root);
	getchar();
}
