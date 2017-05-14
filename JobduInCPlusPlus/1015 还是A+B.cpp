//
//  1015 还是A+B.cpp
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

int a, b, k;

int main(){
    
    while(scanf("%d%d%d",&a,&b,&k)!=EOF){
        if(0==a && 0==b) break;
        int num = pow(10,k);
        int tmp1 = a % num ;
        int tmp2 = b % num ;
        tmp1 = (tmp1+num)%num;
        tmp2 = (tmp2+num)%num;
        if(tmp1 == tmp2)
            printf("-1\n");
        else
            printf("%d\n",a+b);
    }
}

