//
//  main.c
//  线性表初始化
//
//  Created by yuanweizhong on 17/6/3.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char name[20];
    float score;
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
//更新操作
int updateSqList(SqList L,int i,STD x)
{
    if(L.length==0){printf("没有数据，不能更新！\n");return 0;}
    if(i<1||i>L.length){printf("位置不合理！\n");return 0;}
    L.data[i-1]=x;
    return 1;
}
//获取操作
int getSqList(SqList L,int i,STD *x)
{
    if(L.length==0){printf("没有数据！\n");return 0;}
    if(i<1||i>L.length){printf("位置不合理！\n");return 0;}
    *x=L.data[i-1];
    return 1;
}
//定位操作
int locationSqList(SqList L,char * x)
{
    int i;
    if(L.length==0){printf("没有数据！\n");}
    for(i=0;i<L.length;i++)
    {
        if(strcmp(L.data[i].name,x)==0)
            return i+1;
    }
    return 0;
}
//遍历操作
int dispSqList(SqList L)
{
    int i;
    if(L.length==0){printf("没有数据！\n");}
    for(i=0;i<L.length;i++)
        printf("%10s%7.2f\n",L.data[i].name,L.data[i].score);
    return 1;
}
void createSqList(SqList *L,int maxsize)
{
    int n=0;STD x;char yn;
    initSqList(L,maxsize);
    do{
        printf("请输入第%d个学生的姓名和分数，用空格隔开：",n+1);
        scanf("%s%f",x.name,&x.score);
        getchar();
        insertSqList(L, n+1, x);
        n++;
        printf("继续输入吗？Y/N");yn=getchar();
        }
    while(yn=='Y'||yn=='y');
    
}
//主函数
int main()
{
    SqList L;
    createSqList(&L, 10);
}
