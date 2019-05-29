//
//  main.c
//  链栈
//
//  Created by yuanweizhong on 17/6/4.
//  Copyright © 2017年 yuanweizhong. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct node{
    ElemType data;
    struct node *next;
}Snode,*LinkStack;
//初始化操作
void initLinkStack(LinkStack *LS)
{
    *LS=NULL;
}
//判断栈空
int EmptyLinkStack(LinkStack S)
{
    if(S==NULL)return 1;
    else return 0;
}
//得到栈顶
int GetTopLinkStack(LinkStack S,int *e)
{
    if(S==NULL)return 0;
    else *e=S->data;
    return 1;
}
//栈的长度
int LengthLinkStack(LinkStack S)
{
    LinkStack p=S;int n=0;
    while(p){n++;p=p->next;}
    return n;
}
//进栈
void PushLinkStack(LinkStack *LS,int e)
{
    LinkStack p=(LinkStack)malloc(sizeof(Snode));
    p->data=e;
    p->next=*LS;*LS=p;
}
//出栈
int PopLinkStack(LinkStack *LS,int *e)
{
    LinkStack p=*LS;
    if(*LS==NULL)return 0;
    *LS=(*LS)->next;
    *e=p->data;
    free(p);
    return 1;
}
//遍历
int TravelLinkStack(LinkStack S)
{
    LinkStack p=S;
    if(S==NULL){printf("栈空！\n");return 0;}
    while(p){printf("%d",p->data);p=p->next;}
    printf("\n");
    return 1;
}
//创建链栈
void createLinkStack(LinkStack *LS)
{
    int x,yn;
    initLinkStack(LS);
    do{
        printf("请输入进栈数据：\n");
        scanf("%d",&x);
        PushLinkStack(LS, x);
        printf("继续吗？yes＝1，no=0;\n");
        scanf("%d",&yn);
    }while(yn);
    
}
//主函数
int main()
{
    LinkStack S;
    createLinkStack(&S);
}
