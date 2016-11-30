#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int t;
void sort_(int *base,int length){
    int i,j;
    for(i=0;i<length;i++){
        for(j=0;j<length;j++){
            if(*(base+j)>*(base+j+1)){
                t=*(base+j);
                *(base+j)=*(base+j+1);
                *(base+j+1)=t;
            }
        }
    }
}

int compare(const void *a , const void *b ){
    //return *(int *)a - *(int *)b;  //��������
    return *(int *)b - *(int *)a; //��������
}
void main (){
    printf("����������\n");
    int n;
    scanf("%d",&n);
    int * pn=(int *)malloc(n*sizeof(int));
    if(pn==NULL){
        printf("�����ڴ�ʧ�ܣ�");
        exit(0);
    }
    srand((int)time(NULL));
    int i;
    for(i=0;i<n;i++){
        *(pn+i)=rand()%(10001);
    }

    int a=clock();
    qsort(pn,n,sizeof(int),compare);
    printf("��������(qsort)������ʱ%d\n",clock()-a);

    a=clock();
    sort_(pn,n);
    printf("ð������(sort)������ʱ%d\n",clock()-a);
    /*
    printf("�����������������:\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(pn+i));
    }
    */



}
