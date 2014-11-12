//
//  main.c
//  project2
//
//  Created by zyhc on 13-11-24.
//  Copyright (c) 2013年 zyhc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct _BPTree
{
    int num;
    int key[5];
    struct _BPTree *parent;
    int leaf;
    struct _BPTree *link[5];
}BPTree;
BPTree *search(BPTree * T,int x,int *flag,int *q);
BPTree *insert(FILE* fout, BPTree * T,int x);
BPTree* split(BPTree *T);
BPTree* leafsplit(BPTree *T);
int rightmove(BPTree *T,int i);
void PrintTree(FILE *fout, BPTree *T);
int main(int argc, const char * argv[])
{
    
    FILE *fp;
    FILE *fout;
    //    i/o in a file
    int n;
    BPTree *Tree=NULL;
    BPTree *Tmp;
    int i,j;
    int flag, q, x;
    
    fp = fopen("example.in", "r");
    fout = fopen("example.out", "w");
    fp=stdin;
    fout=stdout;
    fscanf(fp, "%d",&n);
    //  input the integer and input it to the B+ Tree
    for (i=0;i<n;i++)
    {
        fscanf(fp, "%d",&x);
        Tree=insert(fout, Tree, x);
    }
    fclose(fp);
    //  print the tree
    PrintTree(fout, Tree);
    fprintf(fout, "\n");
    //    fscanf(fp, "%d", &x);
    //    fscanf(fp, "%d", &x);
    //    flag = 0;
    ////    search x in the tree
    //    Tmp = search(Tree, x, &flag, &q);
    //    if (flag)
    //        fprintf(fout, "FOUND!\n");
    //    else
    //        fprintf(fout, "NOT FOUND!\n");
    fclose(fout);
    return 0;
}
void PrintTree(FILE *fout, BPTree *T)
{
    BPTree *queue[10000];
    int enter[10000]={0};
    //  if enter[i]==1 means I need to output a "\n"
    int p,q;
    int i;
    p=0;q=0;
    //    use a queue to store the output node
    queue[p]=T;
    while (p<=q)
    {
        if (enter[p]==1)
        {
            fprintf(fout, "\n");
        }
        fprintf(fout, "[");
        fprintf(fout, "%d",queue[p]->key[0]);
        //      output the key of the current node
        for (i=1;i<queue[p]->num;i++)
        {
            fprintf(fout, ",%d",queue[p]->key[i]);
        }
        fprintf(fout, "]");
        //      push the link of the current node into the queue
        //      update the array(enter)
        if (queue[p]->leaf==0)
        {
            q++;
            queue[q]=queue[p]->link[0];
            if (p==0 || enter[p]==1)
            {
                enter[q]=1;
            }
        }
        for (i=1;queue[p]->leaf==0 && i<=queue[p]->num;i++)
        {
            q++;
            queue[q]=queue[p]->link[i];
        }
        //      move the point p;
        p++;
    }
}
BPTree *search(BPTree * T,int x,int *flag,int *q)
{
    if (T==NULL)
    {
        //      if T is a NULL tree then return
        return T;
    }
    int i=0;
    //  move i to the appropriate location that T->key[i] is the first key that lagger than x,if x is lagger than every keys, then i will be num;
    while (i<T->num && T->key[i]<=x)
    {
        i++;
    }
    if (i<T->num && T->key[i-1]==x)
    {
        if (T->leaf==1)
        {
            //          it means we finded i
            *flag=1;
            *q=i;
            return T;
        }
        else
        {
            return search(T->link[i],x,flag,q);
        }
    }
    else
    {
        return search(T->link[i],x,flag,q);
    }
}
BPTree *insert(FILE *fout, BPTree * T,int x)
{
    int i,k;
    i=0;
    if (T==NULL)
    {
        T=(BPTree*)malloc(sizeof(BPTree));
        T->num=0;
        T->leaf=1;
        
    }
    while (i<T->num && x>=T->key[i])
    {
        if (x==T->key[i] && T->leaf==1)
        {
            fprintf(fout, "Key %d is duplicated\n",x);
            return T;
        }
        i++;
    }
    if (T->leaf==1)
    {
        rightmove(T,i);
        T->key[i]=x;
        if (T->num==4)
        {
            T=leafsplit(T);
        }
    }
    else
    {
        insert(fout, T->link[i],x);
        if (T->num==3)
        {
            T=split(T);
        }
    }
    return T;
}
BPTree* split(BPTree *T)
{
    BPTree *ret=T;
    int i;
    BPTree *new_node=(BPTree*)malloc(sizeof(BPTree));
    BPTree *par;
    par=T->parent;
    if (par==NULL)
    {
        par=(BPTree*)malloc(sizeof(BPTree));
        par->num=0;
        par->link[0]=T;
        par->leaf=0;
        ret=par;
        T->parent=par;
    }
    new_node->leaf=0;
    new_node->num=1;
    new_node->parent=T->parent;
    new_node->key[0]=T->key[2];
    new_node->link[0]=T->link[2];
    new_node->link[0]->parent=new_node;
    new_node->link[1]=T->link[3];
    new_node->link[1]->parent=new_node;
    T->num=1;
    for (i=0;i<=par->num;i++)
    {
        if (par->link[i]==T)
            break;
    }
    rightmove(par,i);
    par->key[i]=T->key[1];
    par->link[i+1]=new_node;
    return ret;
}
BPTree *leafsplit(BPTree *T)
{
    int i;
    BPTree *ret=T;
    BPTree *new_node=(BPTree*)malloc(sizeof(BPTree));
    BPTree *par;
    par=T->parent;
    if (par==NULL)
    {
        par=(BPTree*)malloc(sizeof(BPTree));
        par->num=0;
        par->link[0]=T;
        par->leaf=0;
        ret=par;
        T->parent=par;
    }
    new_node->num=2;
    new_node->key[0]=T->key[2];
    new_node->key[1]=T->key[3];
    new_node->parent=T->parent;
    new_node->leaf=1;
    T->num=2;
    for (i=0;i<=par->num;i++)
    {
        if (par->link[i]==T)
            break;
    }
    rightmove(par,i);
    par->key[i]=new_node->key[0];
    par->link[i+1]=new_node;
    return ret;
}
int rightmove(BPTree *T,int x)
{
    int i;
    for (i=T->num;i>x;i--)
    {
        T->key[i]=T->key[i-1];
    }
    for (i=T->num+1;i>x+1;i--)
    {
        T->link[i]=T->link[i-1];
    }
    T->num++;
    return 0;
}

