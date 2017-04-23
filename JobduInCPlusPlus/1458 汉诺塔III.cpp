//
//  1458 汉诺塔III.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 23/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
int ans = 0;

long long hanoi(int n){
    if(n==0) return 0;
    if(n==1) return 2;
    return 3*hanoi(n-1)+2;
}

int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",hanoi(n));
    }
}
