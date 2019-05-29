
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    char key[20];
    char name[20];
    char sex;
    int age;
    char birthplace[20];
}STD;
typedef struct{
    STD *data;
    int listsize;
    int length;
}SqList;
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
//线性表删除
int deleteSqList(SqList *L,int i,STD *x)
{
    int k;
    if(L->length==0){printf("没有数据不能删除！\n");return 0;}
    if(i<=0||i>L->length){printf("位置异常！\n");return 0;}
    *x=L->data[i-1];
    for(k=i;k<L->length;k++)
        L->data[k-1]=L->data[k];
    L->length=L->length-1;
    return 1;
}

void createSqList(SqList *L,int maxsize)
{
    int n=0;STD x;char yn;
    initSqList(L,maxsize);
    do{
        printf("请输入第%d个学生的学号和名字，用空格隔开：",n+1);
        scanf("%s%s",x.key,x.name);
        getchar();
        insertSqList(L, n+1, x);
        n++;
        printf("继续输入吗？Y/N");yn=getchar();
    }
    while(yn=='Y'||yn=='y');
    
}
int Find(SqList s,char k[20])
{
    int i;
    strcmp(s.data[0].key,k);
    for(i=s.length;i>=1;i--)
    {
        if(strcmp(s.data[i].key, k)==0)
        {  printf("%s,%s",s.data[i].key,s.data[i].name);
            return 1;}
    }
    
        return 0;
    
}
//主函数
int main()
{
    SqList L;
    createSqList(&L, 10);
    Find(L, "1002");
}
