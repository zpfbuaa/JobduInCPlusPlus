//
//  1002 Grading.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 2017/4/14.
//  Copyright © 2017年 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

double p,t,g1,g2,g3,gj;

double score(){
    if(abs(g1-g2)<=t) return (g1+g2)/2;
    int abs1 = abs(g3-g1);
    int abs2 = abs(g3-g2);
    bool flag1 = abs1<=t ? true : false;
    bool flag2 = abs2<=t ? true : false;
    if(flag1 && !flag2) return (g3+g1)/2;
    if(flag2 && !flag1) return (g3+g2)/2;
    if(flag1 && flag2 ) return max(max(g1,g2),g3);
    else return gj;
}

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&t,&g1,&g2,&g3,&gj)!=EOF){
        printf("%.1lf\n",score());
    }
}
