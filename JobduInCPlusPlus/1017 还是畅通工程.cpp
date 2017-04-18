//
//  1017 还是畅通工程.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 18/04/2017.
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

int findRoot(int x){
    if(tree[x] == -1) return x;
    else{
        int tmp = findRoot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b;
    int cost;
    bool operator < (const Edge &A) const{
        return cost < A.cost;
    }
    Edge(){
        a = 0;
        b = 0;
        cost = 0;
    }
};

int n;
int main(){
    while(scanf("%d",&n)!=EOF && n!=0){
        Edge edge[n*(n-1)/2+1];
        for(int i = 1 ; i <= n*(n-1)/2 ; i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        sort(edge+1, edge+1+n*(n-1)/2);
        for(int i = 1 ; i <= n ; i++){
            tree[i] = -1;
        }
        int ans = 0;
        for(int i = 1 ; i <= n*(n-1)/2 ; i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a!=b){
                tree[a] = b;
                ans+=edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
