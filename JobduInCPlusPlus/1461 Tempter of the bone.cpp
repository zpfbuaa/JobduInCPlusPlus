//
//  1461 Tempter of the bone.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 24/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 8

using namespace std;

int n, m, t;
char plot[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int change[2][4]={{0,0,-1,1},{-1,1,0,0}};//left right up down

struct Pos{
    int x;
    int y;
};
Pos start;
Pos over;
bool flag;
void DFS(Pos pos,int time){
    Pos nextP;
    for(int i = 0 ; i < 4 ; i ++){
        nextP.x = pos.x + change[0][i];
        nextP.y = pos.y + change[1][i];
        if(nextP.x<0 || nextP.x>=n || nextP.y<0 || nextP.y>=m) continue;
        if(plot[nextP.x][nextP.y] == 'X' || visited[nextP.x][nextP.y]==true) continue;
        if(plot[nextP.x][nextP.y] == 'D'){
            if(time+1==t){
                flag = true;
                return;
            }
            else{
                continue;
            }
        }
        visited[nextP.x][nextP.y]=true;
        DFS(nextP,time+1);
        visited[nextP.x][nextP.y]=false;
        if(flag==true) return;
    }
    
}
int main(){
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        
        if(0==n && 0==m && 0==t) break;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",plot[i]);
        }
        flag = false;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                visited[i][j]=false;
                
                if(plot[i][j]=='S'){
                    start.x = i;
                    start.y = j;
                }
                if(plot[i][j]=='D'){
                    over.x = i;
                    over.y = j;
                }
            }
        }
        if((start.x+start.y)%2 == ((over.x+over.y)%2+t%2) %2){
            visited[start.x][start.y]=true;
            DFS(start,0);
        }
        flag == true ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
