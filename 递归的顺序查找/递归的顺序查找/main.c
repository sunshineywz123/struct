
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    int key;
}STD;
typedef struct{
    STD *data;
    int listsize;
    int length;
}SqList;
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define GT(a,b) ((a)>(b))
//初始化线性表
int initSqList(SqList *L,int max)
{
    L->data=(STD *)malloc(max*sizeof(STD));
    if(L->data==NULL){printf("空间申请失败！\n");return 0;}
    L->listsize=max;
    L->length=0;
    return 1;
}
//线性表插入
int insertSqList(SqList *L,int i,STD x)
{
    int k;
    if(i<1||i>L->length+1){printf("插入位置异常！\n");return 0;}
    if(L->length>L->listsize){printf("容量不够！\n");return 0;}
    for(k=L->length;k>=i;k--)
        L->data[k]=L->data[k-1];
    L->data[i-1]=x;
    L->length=L->length+1;
    return 1;
}


void createSqList(SqList *L,int maxsize)
{
    int n=0;STD x;char yn;
    initSqList(L,maxsize);
    do{
        printf("请输入第%d个number：",n+1);
        scanf("%d",&x.key);
        getchar();
        insertSqList(L, n+1, x);
        n++;
        printf("继续输入吗？Y/N");yn=getchar();
    }
    while(yn=='Y'||yn=='y');
    
}
int Find(SqList s,int k,int low,int high)
{
    int mid;
    if(low<high)return (0);
    mid=(low+high)/2;
    if(EQ(s.data[mid].key, k))
    {return mid;}
    if(LT(s.data[mid].key, k))
    {
        return(Find(s, k, mid+1, high));
    }
    else if (GT(s.data[mid].key, k))
    {
        return (Find(s, k, low, mid-1));
    }
    return 0;
}
//主函数
int main()
{
    SqList L;
    createSqList(&L, 100);
    int m=Find(L, 64, 1, 11);
    printf("%d\n",m);
}
