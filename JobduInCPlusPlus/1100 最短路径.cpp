//
//  1100 最短路径.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 19/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 110

using namespace std;

int tree[MAX_SIZE];
int deep[MAX_SIZE];
int len[MAX_SIZE][MAX_SIZE];



int findRoot(int x){
    if(x != tree[x])
        tree[x] = findRoot(tree[x]);
    return tree[x];
}
void init(int n){
    for(int i = 0 ; i < n ; i++){
        tree[i] = i;
        len[i][i] = 0;
    }
}

int myPow(int a, int b)//取模
{
    int ret = 1;
    while(b--)
        ret = (ret*a)%100000;
    return ret;
}

int n,m;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        init(n);
        int a, b;
        int x, y;
        int dist;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&x,&y);
            a = findRoot(x);
            b = findRoot(y);
            if(a==b) continue;
            dist = myPow(2,i);
            for(int j = 0 ; j < n ; j++){
                if(a!=findRoot(j)) continue;
                for(int k = 0 ; k < n ; k++){
                    if(b!=findRoot(k)) continue;
                    len[j][k] = len[k][j] = (len[j][x]+dist+len[y][k])%100000;
                }
            }
            tree[b]=a;
        }
        x = findRoot(0);
        for(int i = 1 ; i < n ; i++){
            if(findRoot(i) != x)
                printf("-1\n");
            else
                printf("%d\n", len[0][i]);
        }
    }
    return 0;
}

