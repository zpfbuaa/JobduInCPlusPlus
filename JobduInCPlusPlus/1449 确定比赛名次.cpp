//
//  1449 确定比赛名次.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 21/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <queue>
#define MAX_SIZE 501

using namespace std;

int inDegree[MAX_SIZE];
vector<int> edge[MAX_SIZE];
priority_queue< int, vector<int>, greater<int> > myQueue;

int n, m;

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        //initation
        for(int i = 1 ; i <= n ; i++){
            inDegree[i]=0;
            edge[i].clear();
        }
        while(!myQueue.empty()) myQueue.pop();
        
        while(m--){
            int p1, p2;
            scanf("%d%d",&p1,&p2);
            edge[p1].push_back(p2);
            inDegree[p2]++;
        }
        for(int i = 1 ; i <= n ; i++){
            if(inDegree[i] == 0){
                myQueue.push(i);
            }
        }
        //this is no need to judge  whether the graph is legal or not.
        int ans = 0;
        while(!myQueue.empty()){
            ans++;
            int nowP = myQueue.top();
            ans == n ? printf("%d\n",nowP) : printf("%d ",nowP);
            myQueue.pop();//remove the node which has the smaller id and inDegree is equal to 0
            
            for(int i = 0 ; i < edge[nowP].size() ; i++){//update the node's inDegree
                inDegree[edge[nowP][i]]--;
                if(inDegree[edge[nowP][i]]==0){
                    myQueue.push(edge[nowP][i]);//add new node(inDegree is 0) to the priority_queue
                }
            }
        }
    }
    return 0;
}
