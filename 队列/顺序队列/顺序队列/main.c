//
//  main.c
//  顺序队列
//
//  Created by yuanweizhong on 17/6/4.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#define MAXLEN 100
#define ElemType int
typedef struct{
    int front;
    int rear;
    int queuesize;
    ElemType data[MAXLEN];
}SqQueue;
//初始化
int initSqQueue(SqQueue *LQ)
{
    LQ->front=LQ->rear=0;
    LQ->queuesize=MAXLEN;
    return 1;
}
//判断队空
int EmptySqQueue(SqQueue Q)
{
    if(Q.front==Q.rear)return 1;
    else return 0;
}
//队长
int LengthSqQueue(SqQueue Q)
{
    return((Q.rear-Q.front)%Q.queuesize);
}
//队头
int HeadSqQueue(SqQueue Q,int *e)
{
    if(Q.rear==Q.front)return 0;
    else *e=Q.data[Q.front];
    return 1;
}
//进队列
int EnSqQueue(SqQueue *LQ,int e)
{
    if((LQ->rear+1)%LQ->queuesize==LQ->front)return 0;
    LQ->data[LQ->rear]=e;
    LQ->rear=(LQ->rear+1)%LQ->queuesize;
    return 1;
}
//出队列
int DeSqQueue(SqQueue *LQ,int *e)
{
    if(LQ->rear==LQ->front)return 0;
    *e=LQ->data[LQ->front];
    LQ->front=(LQ->front+1)%LQ->queuesize;
    return 1;
}
//遍历队列
void TraverSqQueue(SqQueue Q)
{
    int p=Q.front;
    while(p!=(Q.rear+1)%Q.queuesize)
    {
        printf("%d",Q.data[p]);
        p=(p+1)%Q.queuesize;
    }
    printf("\n");
}
