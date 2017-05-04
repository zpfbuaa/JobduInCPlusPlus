//
//  1091 棋盘游戏.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 04/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#define MAX_SIZE 6
//#define debug

using namespace std;

int n, ans = INT_MAX;
int xStart,yStart,xEnd,yEnd;

int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int change[2][4]={{-1,1,0,0},{0,0,-1,1}};


void DFS(int x, int y, int status, int sum){
    int nextX,nextY,cost;
    if(sum < ans){
        if(x==xEnd && y==yEnd){
            ans = sum;
            return ;
        }
        for(int i = 0 ; i < 4 ; i ++){
            nextX = x + change[0][i];
            nextY = y + change[1][i];
            if(!visited[nextX][nextY] && nextX>=0 && nextX<MAX_SIZE && nextY>=0 && nextY<MAX_SIZE){
                cost = map[nextX][nextY]*status;
                visited[nextX][nextY]=true;
                DFS(nextX,nextY,cost%4+1,sum+cost);
                visited[nextX][nextY]=false;
            }
        }
    }
}
int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    scanf("%d",&n);
    while(n--){
        memset(map,0,sizeof(map));
        for(int i = 0 ; i < MAX_SIZE ; i++){
            for(int j = 0 ; j < MAX_SIZE ; j++){
                scanf("%d",&map[i][j]);
                visited[i][j]=false;
            }
        }
        ans = INT_MAX;
        scanf("%d %d %d %d",&xStart,&yStart,&xEnd,&yEnd);
        DFS(xStart,yStart,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
