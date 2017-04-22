//
//  1456 胜利大逃亡.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 22/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#define MAX_SIZE 50
#define WALL 1
#define MOVE 6
using namespace std;

int space[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE][MAX_SIZE];

struct N{
    int x;
    int y;
    int z;
    int t;
};
queue<N>myQueue;

int change[][3]={
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};

int k, a, b, c, t;

int BFS(int a, int b , int c){
    while(!myQueue.empty()){
        N nowP = myQueue.front();
        myQueue.pop();
        for(int i = 0 ; i < MOVE ; i ++){
            int nx = nowP.x + change[i][0];
            int ny = nowP.y + change[i][1];
            int nz = nowP.z + change[i][2];
            if(nx<0 || nx>=a || ny<0 || ny>=b || nz<0 || nz>=c) continue;
            if(space[nx][ny][nz] == WALL) continue;
            if(visit[nx][ny][nz] == true) continue;
            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = nowP.t + 1;
            myQueue.push(tmp);
            visit[nx][ny][nz] = true;
            if(nx==a-1 && ny==b-1 && nz==c-1) return tmp.t;
        }
    }
    return -1;
}

int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d%d%d%d",&a,&b,&c,&t);
        for(int i = 0 ; i < a ; i++){
            for(int j = 0 ; j < b ; j++){
                for(int k = 0 ; k < c ; k++){
                    scanf("%d",&space[i][j][k]);
                    visit[i][j][k]=false;
                }
            }
        }
        while(!myQueue.empty()) myQueue.pop();
        visit[0][0][0] = true;
        N tmp;
        tmp.x=tmp.y=tmp.z=tmp.t=0;
        myQueue.push(tmp);
        int cost = BFS(a,b,c);
        if (cost <= t) printf("%d\n",cost);
        else printf("-1\n");
    }
    return 0;
}
