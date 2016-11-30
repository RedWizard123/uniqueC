#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
int compare(const void *a , const void *b ){
    //return *(int *)a - *(int *)b;  //��������
    return *(int *)b - *(int *)a; //��������
}
int Median3(int *a,int left,int right){
    int center=(left+right)/2;
    if(*(a+left)>*(a+center))Swap(a+left,a+center);
    if(*(a+left)>*(a+right))Swap(a+left,a+right);
    if(*(a+center)>*(a+right))Swap(a+center,a+right);
    Swap(a+center,a+right-1);
    return *(a+right-1);
}
void qsort_(int *base,int left,int right){
    int i,j;
    int p;
    if(left+3<=right){
        p=Median3(base,left,right);
        i=left;
        j=right-1;
        for(;;){
            while(*(++i+base)<p){}
            while(*(--j+base)<p){}
            if(i<j){
                Swap(base+i,base+j);
            }else{
                break;
            }
        }
        Swap(base+i,base+right-1);
        qsort_(base,left,i-1);
        qsort_(base,i+1,right);
    }
    InsertSort(base+left,right-left+1);
}
void Swap(int *a,int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
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
    int a;
    a=clock();
    qsort(pn,n,sizeof(int),compare);
    printf("�������Ŀ���:%d",clock()-a);
    /*����*/

    a=clock();
    InsertSort(pn,n);
    printf("��������:%d\n",clock()-a);
    /*end*/

    /*����*/
    a=clock();
    qsort_(pn,0,n-1);
    printf("���Լ��Ŀ���:%d\n",clock()-a);
    /*end*/

    /*�������е�qsort*/

    /*end*/

    /*
    printf("����������������:\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(pn+i));
    }

    */

}
