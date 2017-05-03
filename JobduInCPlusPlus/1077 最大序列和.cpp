//
//  1077 最大序列和.cpp
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
#define MAX_SIZE 1000001
//#define debug

using namespace std;

int n;
long long a[MAX_SIZE];

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        long long  sum = LONG_LONG_MIN;
        long long tmp = LONG_LONG_MIN;
        for(int i = 0 ; i < n ; i ++){
            scanf("%lld",&a[i]);
            if(tmp>0) tmp+=a[i];
            else tmp = a[i];
            if(tmp>sum) sum=tmp;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
