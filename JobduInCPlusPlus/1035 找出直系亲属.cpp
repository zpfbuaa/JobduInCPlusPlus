//
//  1035 找出直系亲属.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 30/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAX_SIZE 30

//#define debug
using namespace std;

int family[MAX_SIZE];

int n, m;

int find(int a, int b){
    int depth = 1;
    while(family[a]!=-1){
        if(family[a] == b) return depth;
        a = family[a];
        depth++;
    }
    return -1;
}

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF){
        if(0==n && 0==m) break;
        memset(family,-1,sizeof(family));
        char str[4];
        for(int i = 0 ; i < n ; i++){
            scanf("%s",str);
            family[str[1]-'A'] = family[str[2]-'A']=str[0]-'A';
        }
        char ask[2];
        for(int i = 0 ; i < m ; i++){
            scanf("%s",ask);
            int x = find(ask[0]-'A',ask[1]-'A');
            int y = find(ask[1]-'A',ask[0]-'A');
            int maxDepth = max(x,y);
            if(maxDepth<=0){
                printf("-\n");
            }
            else if(x>0){
                if(maxDepth==1){
                    printf("parent\n");
                }
                else{
                    for(int i = 2 ; i < maxDepth ; i++){
                        printf("great-");
                    }
                    printf("grandparent\n");
                }
            }
            else if(y>0){
                if(maxDepth==1){
                    printf("child\n");
                }
                else{
                    for(int i = 2 ; i < maxDepth ; i++){
                        printf("great-");
                    }
                    printf("grandchild\n");
                }
            }
            
        }
    }
    return 0;
}
