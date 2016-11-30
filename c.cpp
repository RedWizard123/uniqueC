#include<stdio.h>
#include<stdlib.h>
#include "ChainList.h"

int main(){
    ChainList a;
    int i;
    for(i=0;i<10;i++){
        char* p=(char*)malloc(10*sizeof(char));
        gets(p);
        a.Add(p);
    }
    for(i=0;i<a.Count();i++){
        printf("%s\t",(char *)a.Item(i));
    }

}
