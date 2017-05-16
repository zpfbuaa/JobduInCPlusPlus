//
//  1020 最小长方形.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 29/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;

int x, y;
int minx,miny;
int maxx,maxy;
bool flag;

void init(){
    flag = true;
    minx = miny = 232;
    maxx = maxy = -232;
}
int main(){
    
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    init();
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x!=0 || y!=0){
            minx = min(minx,x);
            miny = min(miny,y);
            maxx = max(maxx,x);
            maxy = max(maxy,y);
            flag = false;
        }
        if(flag && x==0 && y==0){
            break;
        }
        if(x==0 && y==0){
            printf("%d %d %d %d\n",minx,miny,maxx,maxy);
            init();
        }
    }
}
