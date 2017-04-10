//
//  1438 最小公倍数.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 10/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int a, b;

int main(){
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0 && b==0) break;
        printf("%d\n",a*b/gcd(a,b));
    }
}
