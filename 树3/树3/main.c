#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild,*rchild;
}BiTree;

BiTree *Intopost(ElemType in[],ElemType post[],int l1,int h1,int l2,int h2)   //in和post中分别存放中序序列和后序序列，l1,h1,l2,h2分别是两序列首尾节点的下标
{
    BiTree *t;
    int i;
    t=(BiTree *)malloc(sizeof(BiTree));  //申请节点
    t->data=post[h2];  //后序遍历序列最后一个元素是根节点数据
    for(i=l1;i<=h1;i++)
        if(in[i]==post[h2]) break;  //在中序中查找根结点
    if(i==1) t->lchild=NULL;    //处理左子树
    else
        t->lchild=Intopost(in,post,l1,i-1,l2,l2+i-l1-1);
    if(i==h1) t->rchild=NULL;   //处理右子树
    else
        
        t->rchild=Intopost(in, post,i+1,h1,l2+i-l1,h2-1 );
    return(t);
}

int main(int argc, const char * argv[]) {
    ElemType in[]={'D','B','E','A','F','C'};
    ElemType post[]={'D','E','B','F','C','A'};
    BiTree *Tree;
    Tree=Intopost(in,post,1,6,7,12);

    return 0;
}
