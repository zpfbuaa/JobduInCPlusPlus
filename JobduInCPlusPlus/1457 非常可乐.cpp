//
//  1457 非常可乐.cpp
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
#define MAX_SIZE 101
using namespace std;

int s, n, m;

struct N{
    int a;
    int b;
    int c;
    int t;
};

queue<N> myQueue;
bool visit[MAX_SIZE][MAX_SIZE][MAX_SIZE];

void x2y(int &x,int size_x, int &y,int size_y){
    if(size_y - y >= x){
        y+=x;
        x = 0;
    }else{
        x -=(size_y-y);
        y = size_y;
    }
}

int BFS(int s, int n, int m){
    while(!myQueue.empty()){
        N nowP = myQueue.front();
        myQueue.pop();
        int a, b, c;
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(a,s,b,n);// a--->b
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(a,s,c,m);// a--->c
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(b,n,a,s);// b--->a
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(b,n,c,m);// b--->c
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(c,m,a,s);// c--->a
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
        a = nowP.a;
        b = nowP.b;
        c = nowP.c;
        x2y(c,m,b,n);// c--->b
        if(visit[a][b][c]==false){
            visit[a][b][c]=true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = nowP.t+1;
            if((a==s/2 && b==s/2) || (a==s/2 &&c==s/2) || (b==s/2 && c==s/2) ) return tmp.t;
            myQueue.push(tmp);
        }
    }
    return -1;
}

int main(){
    while(scanf("%d%d%d",&s,&n,&m)!=EOF){
        if(s==0) break;
        if(s%2==1){
            printf("NO\n");
            continue;
        }
        for(int i = 0 ; i <= s ; i++){
            for(int j = 0 ; j <= n ; j++){
                for(int k = 0 ; k <= m ; k++){
                    visit[i][j][k]=false;
                }
            }
        }
        while(!myQueue.empty()) myQueue.pop();
        
        N tmp;
        tmp.a = s;
        tmp.b = tmp.c = tmp.t = 0;
        myQueue.push(tmp);
        visit[s][0][0]=true;
        int ans = BFS(s,n,m);
        ans == -1 ? printf("NO\n") : printf("%d\n",ans);
    }
}
