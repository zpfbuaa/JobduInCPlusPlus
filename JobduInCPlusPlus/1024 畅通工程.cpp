//
//  1024 畅通工程.cpp
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
#define MAX_SIZE 222

using namespace std;

int tree[MAX_SIZE];
int num[MAX_SIZE];

int findRoot(int x){
    if(tree[x] == -1) return x;
    else{
        int tmp = findRoot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a;
    int b;
    int cost;
    bool operator < (const Edge &A) const{
        return cost < A.cost;
    }
};

int n, m;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0) break;
        Edge edge[n*(n-1)/2+1];

        for(int i = 1 ; i <= m ; i++){
            tree[i] = -1;
            num[i] = 1;
        }
        
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        //important to sort the each line in the  edge array
        sort(edge+1,edge+1+n);// start from i=1 to i=n thus sort(edge+1, edge+1+n)
        
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a!=b){
                tree[a] = b;
                num[b]+=num[a]; // merge a's aggregate into b
                ans+=edge[i].cost;
            }
        }
        //the root must have total number village == m
        bool flag = false;
        for(int i = 1 ; i <= m ; i++){
            if(tree[i]==-1 && num[i]==m){//the root is tree[i] == -1
                flag = true;
                break;
            }
        }
        flag == true ? printf("%d\n",ans) : printf("?\n");
    }
    return 0;
}
