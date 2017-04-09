//
//  1078 二叉树遍历.cpp
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

struct Node{//the tree
    Node *lchild;
    Node *rchild;
    char c;
}tree[50];

int loc;
Node *creat(){//init the tree
    tree[loc].lchild=tree[loc].rchild=NULL;
    return &tree[loc++];
}

char str1[30], str2[30];//hold the input string
void postOrder(Node *T){//postOrder to print
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    printf("%c",T->c);
}

Node *build(int s1, int e1, int s2, int e2){
    Node* ret = creat();
    ret->c=str1[s1];
    int rootIdx=0;//find the index of next root
    for(int i = s2 ; i <=e2 ;  i++){
        if(str2[i] == str1[s1]){
            rootIdx=i;
            break;
        }
    }
    if(rootIdx!=s2){
        ret->lchild=build(s1+1, s1+(rootIdx-s2), s2, rootIdx-1);//left tree build
    }
    if(rootIdx!=e2){
        ret->rchild=build(s1+(rootIdx-s2)+1, e1, rootIdx+1, e2);//right tree build
    }
    return ret;//the root
}

int main(){
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        loc=0;
        int l1 = (int)strlen(str1);
        int l2 = (int)strlen(str2);
        Node* T = build(0,l1-1,0,l2-1);//build tree
        postOrder(T);//print the postOrder
        printf("\n");//mind the '\n'
    }
    return 0;
}
