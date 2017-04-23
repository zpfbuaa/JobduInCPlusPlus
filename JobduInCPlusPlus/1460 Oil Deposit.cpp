//
//  1460 Oil Deposit.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 23/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 101

using namespace std;

char plot[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int change[2][8]={{-1,-1,-1,0,0,1,1,1},{-1,0,1,-1,1,-1,0,1}};

int n, m;

void DFS(int x, int y){
    for(int i = 0 ; i < 8 ; i++){
        int nx = x + change[0][i];
        int ny = y + change[1][i];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(plot[nx][ny]=='*') continue;
        if(visited[nx][ny]==true) continue;
        visited[nx][ny]=true;
        DFS(nx,ny);
    }
    return;
}
int main(){
    //    for(int i = 0 ; i < 8 ; i ++){
    //        cout<<"change[0]["<<i<<"] = "<<change[0][i]<<" ";
    //        cout<<"change[1]["<<i<<"] = "<<change[1][i]<<endl;
    //    }
    while(scanf("%d%d",&n,&m)!=EOF){
        if(0==n && 0==m) break;
        
        for(int i = 0 ; i < n ; i++){
            scanf("%s",plot[i]);
        }
        
        for(int i = 0; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                visited[i][j]=false;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(visited[i][j]==true) continue;
                if(plot[i][j]=='*') continue;
                DFS(i,j);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
