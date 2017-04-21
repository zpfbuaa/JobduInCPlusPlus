//
//  1448 Legal or Not.cpp
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
#include <vector>
#include <queue>
#define MAX_SIZE 110
using namespace std;

vector<int> edge[MAX_SIZE];
queue<int> q;
int inDegree[MAX_SIZE];

int n, m;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(0==n && 0==m) break;
        for(int i = 0 ; i < n ; i++){
            inDegree[i] = 0;
            edge[i].clear();
        }
        while(m--){
            int a, b;
            scanf("%d%d",&a,&b);
            inDegree[b]++;
            edge[a].push_back(b);
        }
        while(!q.empty()) {
            q.pop();
        }
        for(int i = 0 ; i < n ; i++){//add all the inDegree node into the queue
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty()){//find all the inDegree == 0 and remove it
            int nowP = q.front();
            q.pop();
            ans++;
            for(int i = 0 ; i < edge[nowP].size() ; i++){//and also reduce the node next to the removed node
                inDegree[edge[nowP][i]]--;
                if(inDegree[edge[nowP][i]] == 0){//if inDegree is zero then put this node into the queue
                    q.push(edge[nowP][i]);
                }
            }
        }
        ans == n ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
