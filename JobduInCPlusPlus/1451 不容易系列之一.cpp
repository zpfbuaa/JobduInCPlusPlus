//
//  1451 不容易系列之一.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 24/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 22

using namespace std;

int n;
long long a[MAX_SIZE];

int main(){
    while(scanf("%d",&n)!=EOF){
        a[1] = 0;
        a[2] = 1;
        for(int i = 3 ; i <= n ; i++){
            a[i]= (i-1)*a[i-1]+(i-1)*a[i-2];
        }
        printf("%lld\n",a[n]);
    }
    return 0;
}
