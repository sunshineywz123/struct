//
//  main.c
//  链队列
//
//  Created by yuanweizhong on 17/6/4.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define ElemType char
typedef struct node{
    ElemType data;
    struct node *next;
}QNode,*QueueLink;
typedef struct {
    QueueLink front;
    QueueLink rear;
}QLink;
//初始化操作
int initSqQueue(QLink *LQ)
{
    LQ->front=LQ->rear=(QueueLink)malloc(sizeof(QNode));
    if(LQ->front==NULL)return 0;
    LQ->front->next=NULL;
    return 1;
}
//判断队空
int EmptySqQueue(QLink Q)
{
    if(Q.front==Q.rear)return 1;
    else return 0;
}
//队列长度
int LengthSqQueue(QLink Q)
{
    QueueLink p;
    int n=0;
    if(Q.front==Q.rear)return 0;
    p=Q.front->next;
    while(p){
        n++;
        p=p->next;
    }
    return n;
}
//队头
int GetHeadLinkQueue(QLink Q,ElemType e)
{
    if(Q.rear==Q.front)return 0;
    strcpy(e,Q.front->next->data);
    return 1;
}
//进队列
int ENLinkQueue(QLink *LQ,ElemType e)
{
    QueueLink p;
    p=(QueueLink)malloc(sizeof(QNode));
    if(p==NULL)return 0;
    strcpy(p->data,e);
    p->next=NULL;
    LQ->rear->next=p;
    LQ->rear=p;
    return 1;
}
//出队列
int DeLinkQueue(QLink *LQ,ElemType e)
{
    QueueLink p;
    if(LQ->rear==LQ->front)return 0;
    strcpy(e,LQ->front->next->data);
    p=LQ->front->next;
    LQ->front->next=p->next;
    if(LQ->rear==p)
        LQ->rear=LQ->front;
    free(p);
    return 1;
}
//遍历队列
void TraverLinkQueue(QLink Q)
{
    QueueLink p=Q.front->next;
    while(p)
    {
        printf("%s\n",p->data);
        p=p->next;
    }
}
