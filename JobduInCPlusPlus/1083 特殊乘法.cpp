//
//  1083 特殊乘法.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 09/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int n, m;
int a[12],b[12];

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int tmp1 = n, tmp2 = m;
        int len1 = 0, len2 = 0;
        while(tmp1 != 0){
            a[len1++]=tmp1%10;
            tmp1 = tmp1/10;
        }
        while(tmp2 != 0){
            b[len2++]=tmp2%10;
            tmp2 = tmp2/10;
        }
        int ans = 0;
        for(int i = 0 ; i < len1 ; i++){
            for(int j = 0 ; j < len2; j++){
                ans += a[i]*b[j];
            }
        }
        printf("%d\n",ans);
    }
}
