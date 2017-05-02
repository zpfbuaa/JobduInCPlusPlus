//
//  1048 判断三角形类型.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 02/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
//#define debug
using namespace std;

int a, b, c;

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        int maxNum = max(a,max(b,c));
        int minNum = min(a,min(b,c));
        int midNum = a + b + c - maxNum - minNum;
        int tmp1 = minNum * minNum + midNum * midNum;
        int tmp2 = maxNum * maxNum;
        if(tmp1 == tmp2){
            printf("直角三角形\n");
        }
        else if(tmp1 < tmp2){
            printf("钝角三角形\n");
        }
        else if(tmp1 > tmp2){
            printf("锐角三角形\n");
        }
    }
    return 0;
}
