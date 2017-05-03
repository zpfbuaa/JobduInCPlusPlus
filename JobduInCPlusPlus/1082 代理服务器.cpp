//
//  1082 代理服务器.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 03/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX_SIZE 1001
#define MAX_SERVER 5001
//#define debug
using namespace std;

int n, m;

struct Server{//define the struct of server
    int x, y, z, w;
    bool operator == (const Server &a) const{//reload the == operator
        return (x==a.x && y==a.y && z==a.z && w==a.w);
    }
};

Server s1[MAX_SIZE];
Server s2[MAX_SERVER];

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%d",&n)!=EOF){
        for(int i = 0 ; i < n ; i++){
            scanf("%d.%d.%d.%d",&s1[i].x,&s1[i].y,&s1[i].z,&s1[i].w);
        }
        scanf("%d",&m);
        for(int i = 0 ; i < m ; i++){
            scanf("%d.%d.%d.%d",&s2[i].x,&s2[i].y,&s2[i].z,&s2[i].w);
        }
        if(1==n){//special case
            int i;
            for(i = 0 ; i < m ; i++){
                if(s1[0]==s2[i]){
                    break;
                }
            }
            if(i<m) printf("-1\n");
            else printf("0\n");
        }
        else{
            bool loopFlag = true;
            int start=0, ans = 0, idx = 0;
            int maxIdx;
            while(loopFlag){
                maxIdx = -1;
                loopFlag = false;
                for(int i = 0 ; i < n ; i++){
                    idx = start;
                    while(idx < m && !(s1[i]==s2[idx])){
                        idx++;
                    }
                    maxIdx = max(maxIdx,idx);// find the last appear server
                }
                if(maxIdx < m){ //judge whether this server can reach all the other servers
                    ans++;
                    loopFlag = true;
                }
                start =  maxIdx + 1; //update the start Idx
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
