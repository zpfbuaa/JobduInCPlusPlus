//
//  1008 最短路径问题.cpp
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
#include <vector>

#define MAX_SIZE 1010

using namespace std;

int n, m;


struct E{//the adjective matrix
    int next;
    int len;
    int cost;
};

vector<E> edge[MAX_SIZE];

int dis[MAX_SIZE];//dis[i] keep the length from start to [i] so and cost[i],mark[i]
int cost[MAX_SIZE];
bool mark[MAX_SIZE];

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(0==n && 0==m) break;
        for(int i = 1 ; i <= n ; i++){
            edge[i].clear();//clear the matrix
        }
        for(int i = 1 ; i <= m ; i++){
            int a, b, len, cost;
            scanf("%d%d%d%d",&a,&b,&len,&cost);
            E tmp;
            tmp.len = len;
            tmp.cost = cost;
            tmp.next = b;
            edge[a].push_back(tmp);//the node a has those info and the next node is b
            tmp.next = a;
            edge[b].push_back(tmp);//the node b has those info and the next node is a
        }
        
        int s, t;
        scanf("%d%d",&s,&t);//start node and end node
        
        for(int i = 1 ; i <= n ; i++){//init
            dis[i] = -1;
            mark[i] = false;
            cost[i] = 0;
        }
        
        dis[s]=0;
        mark[s] = true;//whether this node is in the aggregate
        int newP = s;//new dot needed to add
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <edge[newP].size(); j++){//all the nodes in the newP
                //get info
                int next = edge[newP][j].next;
                int len = edge[newP][j].len;
                int cos = edge[newP][j].cost;
                
                if(mark[next] == true) continue;//already in the aggreagte
                //can't reach or has a less length or has smaller cost
                if(dis[next]==-1 || dis[next] > dis[newP]+len || (dis[next]==dis[newP]+len && cost[next] > cost[newP]+cos)){
                    dis[next] = dis[newP] + len;
                    cost[next] = cost[newP] + cos;
                }
            }
            int min = 2121212121;
            for(int j = 1 ; j <= n ; j++){//find a new node to add
                if(mark[j]==true) continue;//not in the aggregate
                if(dis[j] == -1) continue;//can't  reach
                if(dis[j]<min){
                    min = dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        printf("%d %d\n",dis[t],cost[t]);
    }
    return 0;
}
