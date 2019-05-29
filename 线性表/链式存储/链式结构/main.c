//
//  main.c
//  链式结构
//
//  Created by yuanweizhong on 17/6/4.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
typedef struct {
    char name[20];
    float score;
}STD;
#define  Elemtype STD
typedef struct node
{
    Elemtype data;
    struct node *next;
}Lnode,* LinkList;
//初始化操作
int initLinList(LinkList * L)
{
    *L=(LinkList)malloc(sizeof(Lnode));
    if(*L==NULL)return 0;
    (*L)->next=NULL;
    return 1;
}
//插入操作
int insertLinkList(LinkList L,int i,STD x)
{
    LinkList p=L,s;
    int pos=0;    //记住P的位置
    //让p记住第i－1个结点，pos记住p指向结点的位置
    while(p!=NULL&&pos<i-1){p=p->next;pos=pos+1;}
    /*如果i过大，会出现p＝＝NULL；如果i过小，会出现pos>i-1*/
    if(p==NULL||pos>i-1){printf("插入位置不合理!\n");return 0;}
    s=(LinkList)malloc(sizeof(Lnode));
    s->data=x;
    s->next=p->next;
    p->next=s;  //将s指向的新结点在指定位置插入
    return 1;
}
//删除操作
int deletLinkList(LinkList L,int i)
{
    LinkList q,p=L;
    int pos=0;
    while(p->next!=NULL&&pos<i-1){p=p->next;pos=pos+1;}
    if(p->next==NULL||pos>i-1){printf("链表为空或删除位置不合理!\n");return 0;}
    q=p->next;
    p->next=q->next;free(q);
    return 1;
}
//更新操作
int updateLinkList(LinkList L,int i,STD x)
{
    LinkList p=L->next;
    int n=1;
    while(p&&n<i){p=p->next;n++;}
    if(p==NULL||n>i){printf("位置不合理！\n");return 0;}
    p->data=x;
    return 1;
}
//获取操作
int getLinkList(LinkList L,int i,STD *x)
{
    LinkList p=L->next;
    int n=1;
    while(p&&n<i){p=p->next;n++;}
    if(p==NULL||n>i){printf("位置不合理，不能获取！\n");return 0;}
    *x=p->data;
    return 1;
}
//定位操作
/*int locationLinkList(LinkList L,char * name)
{
    LinkList p=L->next;
    int j=1;
    while(p)
    if(strcmp(p->data.name,name))
    {p=p->next;j++;}
    else return j;
    if(p==NULL)
        return 0;
 
}*/
//求长度操作
int lengthLinkList(LinkList L)
{
    LinkList p=L->next;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
//遍历操作
int diapLinkList(LinkList L)
{
    LinkList p=L->next;
    if(p==NULL){printf("没有数据！\n");return 0;}
    while(p)
    {
        printf("%10s%7.2f\n",p->data.name,p->data.score);
        p=p->next;
    }
    return 1;
}
//创建链表
void creatLinkList(LinkList *L)
{
    int n=1;
    STD x;
    LinkList p;
    char yn;
    initLinList(L);
    do{
        printf("请输入第%d个学生的姓名和分数，用空格隔开：",n);
        scanf("%s%f",x.name,&x.score);
        getchar();  //空读回车
        p=(LinkList)malloc(sizeof(Lnode));
        p->data=x;
        insertLinkList(*L, n, x);
        printf("继续输入吗？Y/N：");
        yn=getchar();
    }while(yn=='Y'||yn=='y');
}
void main()
{
    LinkList L;
    creatLinkList(&L);
    }
