//
//  1084 整数拆分.cpp
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
#define MOD 1000000000
#define MAX_SIZE 500001
using namespace std;

int n;

int a[MAX_SIZE];

void cal(){
    memset(a, 0, sizeof(a));
    a[0]=1;
    for(int i = 1 ; i < MAX_SIZE ; i++){
        a[i] = (a[i-1]+a[i/2])%MOD;
    }
}
int main(){
    cal();
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",a[n/2]);
    }
    return 0;
}

