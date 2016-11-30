#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<pThread.h>
#include <stdlib.h>
#include <stdio.h>

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex){
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1){
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}

//�ڲ�ʹ�õݹ�
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex){
    int midIndex;
    if(startIndex < endIndex){
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}
int compare(const void *a , const void *b ){
    return *(int *)b - *(int *)a;
}
void InsertSort(int *base,int n){
    int j,p;
    int temp;
    for(p=1;p<n;p++){
        temp=*(base+p);
        for(j=p;j>0&&*(base+j-1)>temp;j--){
            *(base+j)=*(base+j-1);
        }
        *(base+j)=temp;
    }
}
void sort(int *a, int left, int right){
    if(left >= right){
        return;
    }
    int i = left;
    int j = right;
    int key = a[left];
    while(i < j){
        while(i < j && key <= a[j]){
            j--;
        }
        a[i] = a[j];
        while(i < j && key >= a[i]){
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}
void main(){
	printf("Insert amount:\n");
    int n;
    scanf("%d",&n);
    int * pn=(int *)malloc(n*sizeof(int));
    if(pn==NULL){
        printf("Error!");
        exit(0);
    }
    int i,a;
	/*1*/

	srand((int)time(NULL));
    for(i=0;i<n;i++){
        *(pn+i)=(rand()%(10001))*(rand()%(10001));
    }
	a=clock();
	sort(pn,0,n);
	printf("1:spend:%10dms\n",clock()-a);
	/*End*/

	/*2*/
    int * pn_=(int *)malloc(n*sizeof(int));
	srand((int)time(NULL));
    for(i=0;i<n;i++){
        *(pn+i)=(rand()%(10001))*(rand()%(10001));
    }
	a=clock();
	MergeSort(pn,pn_,0,n);
	printf("2:spend:%10dms\n",clock()-a);
	/*End*/

	/*3*/
	srand((int)time(NULL));
	for(i=0;i<n;i++){
        *(pn+i)=(rand()%(10001))*(rand()%(10001));
    }
	a=clock();
	qsort(pn,n,sizeof(int),compare);
	printf("3:spend:%10dms\n",clock()-a);
	/*End*/

	/*for(i=0;i<n;i++){
		printf("%d\t",*(pn+i));
	}*/
}
