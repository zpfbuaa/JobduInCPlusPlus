//
//  1009 二叉搜索树.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 09/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct Node{
    Node *lchild;
    Node *rchild;
    int c;
}tree[110];

int loc;
char str1[25],str2[25];//hold the inOrder and postOrder.
int size1,size2;

char *str;//keep the reverse characters. str is just a pointer
int *size;//keep the size of array. str is just a pointer

Node *creat(){
    tree[loc].lchild=tree[loc].rchild=NULL;
    return &tree[loc++];
}

void inOrder(Node *T){
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    str[(*size)++]=T->c+'0';//size++ and put the character into the str array
    if(T->rchild!=NULL)
        inOrder(T->rchild);
}

void postOrder(Node *T){
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    str[(*size)++]=T->c+'0';//size++ and put the character into the str array
}

Node *insert(Node *T,int x){
    if(T==NULL){
        T=creat();
        T->c=x;
        return T;
    }
    else if(x<T->c){
        T->lchild=insert(T->lchild, x);
    }
    else if(x>T->c){
        T->rchild=insert(T->rchild, x);
    }
    return T;
}

int n;


int main(){
    
    while(scanf("%d",&n)!=EOF&&n!=0){
        char temp[12];
        loc=0;
        Node *T=NULL;
        scanf("%s",temp);
        for(int i = 0 ; temp[i]!=0; i++){
            T=insert(T, temp[i]-'0');
        }
        size1=0;
        str=str1;//now str point to str1
        size=&size1;//now size point to size1
        postOrder(T);
        inOrder(T);
        str1[size1]=0;
        while(n--){
            scanf("%s",temp);
            Node *T2 = NULL;
            for(int i = 0 ; temp[i]!=0 ; i++){
                T2 = insert(T2, temp[i]-'0');
            }
            size2=0;
            str=str2;
            size=&size2;
            postOrder(T2);
            inOrder(T2);
            str2[size2]=0;
            puts(strcmp(str1,str2)==0 ? "YES" : "NO");
        }
    }
    return 0;
}
