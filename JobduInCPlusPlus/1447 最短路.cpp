//
//  1447 最短路.cpp
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

int n, m;
int dist[MAX_SIZE][MAX_SIZE];

void init(){
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i!=j){
                dist[i][j] = -1;
            }
            else{
                dist[i][j] = 0;
            }
        }
    }
}
void floyd(){
    for(int k = 1 ; k <= n ; k ++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(dist[i][k]==-1 || dist[k][j]==-1) continue;
                else if(dist[i][j]==-1 || dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(0==n && 0==m) break;
        init();
        while(m--){
            int a,b,cost;
            scanf("%d%d%d",&a,&b,&cost);
            dist[a][b] = dist[b][a] = cost;
        }
        floyd();
        printf("%d\n",dist[1][n]);
    }
    return 0;
}
