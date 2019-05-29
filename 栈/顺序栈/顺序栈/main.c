//
//  main.c
//  顺序栈
//
//  Created by yuanweizhong on 17/6/4.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct stack
{
    ElemType * data;
    int top;
    int stacksize;
}SqStack;
//初始化操作
int initSqStack(SqStack *LS,int max)
{
    LS->data=(ElemType *)malloc(sizeof(ElemType));
    if(LS->data==NULL){printf("空间申请失败！\n");exit(0);}
    LS->top=-1;
    LS->stacksize=max;
    return 1;
}
//判断栈空
int SqStackEmpty(SqStack S)
{
    if(S.top==-1)return 1;
    else return 0;
}
//得到栈顶
int GetTop(SqStack S,int *e)
{
    if(SqStackEmpty(S)==1)return 0;
    *e=S.data[S.top];
    return 1;
}
//栈的长度
int LengthSqStack(SqStack S)
{
    return S.top+1;
}
//进栈
int PushSqStack(SqStack *LS,int e)
{
    if(LS->stacksize==LS->top+1){return 0;}
    LS->top++;
    LS->data[LS->top]=e;
    return 1;
}
//出栈
int PopSqStack(SqStack *LS,int *e)
{
    if(LS->top==-1)return 0;
    *e=LS->data[LS->top];
    LS->top--;
    return 1;
}
//遍历栈
int TraversSqStack(SqStack S)
{
    int k;
    if(S.top==-1){printf("栈空！\n");}
    for(k=S.top;k>=0;k--)printf("%d",S.data);
    printf("\n");
    return 1;
}
//创建栈
void createSqStack(SqStack *LS,int max)
{
    int x,yn;
    initSqStack(LS,max);
    do{
        printf("请输入入栈的数据：");scanf("%d",&x);
        PushSqStack(LS, x);
        printf("继续吗？yes=1;no=0;\n");
        scanf("%d",&yn);
    }while(yn);
}
//主函数
int main()
{
    SqStack S;
    createSqStack(&S, 100);
}
