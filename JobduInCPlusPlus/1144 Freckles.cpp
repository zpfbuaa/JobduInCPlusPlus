//
//  1144 Freckles.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 18/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 110


using namespace std;

int tree[MAX_SIZE];

int findRoot(int x){// find the root of x
    if(tree[x] == -1) return x;
    else{
        int tmp = findRoot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

struct Edge{// define the edge which have line  a and  line b
    int a, b;
    double cost; // the length of point a to point b
    bool operator < (const Edge &A) const{
        return cost < A.cost;
    }
};


struct Point{//define the point
    double x, y;//(x,y) the position of this dot
    double getDistance(Point A){//get the lenght between (x,y) and (A.x, A.y)
        double tmp = (x-A.x)*(x-A.x) + (y-A.y)*(y-A.y);
        return sqrt(tmp);
    }
};

int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        
        Edge edge[n*(n-1)/2+1];
        Point point[n+1];
        
        for(int i = 1 ; i <= n ; i++){
            scanf("%lf%lf",&point[i].x,&point[i].y);//input the pos of (x,y)
            tree[i]=-1;//init the node i
        }
        int line_id = 0;//define the id of the line
        for(int i = 1 ; i <= n ; i++){
            for(int j = i+1 ; j <= n ; j++){
                edge[line_id].a = i;
                edge[line_id].b = j;
                edge[line_id].cost = point[i].getDistance(point[j]);//cal the length point[i] to point[y]
                line_id++;
            }
        }
        
        sort(edge,edge+line_id);// from low to high
        
        double ans = 0;
        
        for(int i = 0 ; i < line_id ; i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a!=b){//merge the a node to b‘s aggregate
                tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
    
}
