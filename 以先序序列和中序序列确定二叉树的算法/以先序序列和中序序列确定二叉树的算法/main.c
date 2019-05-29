#include<stdio.h>
#include<stdlib.h>
struct BiTree{
  
    struct BiTreeNode *left;
    struct BiTreeNode *right;
};
void CrtBT(struct BiTree *T,char pre[],char ino[],int ps,int is,int n)
{
    if(n==0) *T=NULL;
    else{
        int k;
        k=Search(ino,pre[ps]);
        if(k==-1) *T=NULL;
        else
        {
            if(!(*T=(struct BiTree *) malloct(sizeof(BiTNode)))) exit(0);
            (*T).data=pre[ps];
            if(k==is) (*T).lchild=NULL;
            else CrtBT(&(*T).lchild,pre,ino,ps+1,is,k-is);
            if(k==is+n-1) (*T).rchild=NULL;
            else CrtBT(&(*T).rchild,pre,ino,ps+1+(k-is),k+1,n-(k-is)-1)
        }
    }
    
}
