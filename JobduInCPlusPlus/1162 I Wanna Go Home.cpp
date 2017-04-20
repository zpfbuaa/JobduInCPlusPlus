//
//  1162 I Wanna Go Home.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 20/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX 0x7fffffff
using namespace std;

int n ,m;

int grah[601][601];
int sup[601];


void dijkstra()
{
    int dis[601];
    bool mark[601] = {false};
    
    for(int i = 0 ; i < n; i++)
        dis[i] = grah[0][i];
    
    int s = 0;
    mark[s] = true;
    dis[s] = 0;
    int newP = s;
    for(int i = 1 ; i <= n ; i++){
        for( int j = 0 ; j < n ; j++){
            if( !mark[j] && grah[newP][j] < MAX && !(sup[newP] == 2 && sup[j] == 1)){
                if(dis[j] > dis[newP] + grah[newP][j])
                    dis[j] = dis[newP] + grah[newP][j];
            }
        }
        int min = MAX;
        for(int j = 0 ; j < n ; j++){
            if( !mark[j] && min > dis[j]){
                min = dis[j];
                newP = j;
            }
        }
        mark[newP] = true;
    }
    if(dis[1] < MAX) printf("%d\n",dis[1]);
    else  printf("-1\n");
}


int main(){
    while(scanf("%d",&n)!=EOF && n!=0){
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i==j) {
                   grah[i][j]=0;
                }
                else grah[i][j]=MAX;
            }
        }
        scanf("%d",&m);
        int x, y, len;
        while(m--){
            scanf("%d%d%d",&x,&y,&len);
            grah[x-1][y-1] = grah[y-1][x-1]=len;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&sup[i]);
        }
        dijkstra();
    }
    return 0;
}

