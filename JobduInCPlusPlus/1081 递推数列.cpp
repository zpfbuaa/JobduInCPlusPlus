//
//  1081 递推数列.cpp
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
#define MOD 10000
using namespace std;

int a0, a1, p, q, k;

int metrix[2][2];
/*
 *  metrixMul
 *
 *  | ak   |   | p q |   | ak-1 |
 *  |      | = |     | * |      |
 *  | ak-1 |   | 1 0 |   | ak-2 |
 *
 *  metrixPow
 *
 *  | ak   |   | p q |(k-1)   | a1 |
 *  |      | = |     |     *  |    |
 *  | ak-1 |   | 1 0 |        | a0 |
 *
 */
void metrixMul(int p1[2][2], int p2[2][2]){
    int tmp[2][2];
    tmp[0][0] = ((p1[0][0]*p2[0][0])%MOD + p1[0][1]*p2[1][0]%MOD)%MOD;
    tmp[0][1] = ((p1[0][0]*p2[0][1])%MOD + p1[0][1]*p2[1][1]%MOD)%MOD;
    tmp[1][0] = ((p1[1][0]*p2[0][0])%MOD + p1[1][1]*p2[1][0]%MOD)%MOD;
    tmp[1][1] = ((p1[1][0]*p2[0][1])%MOD + p1[1][1]*p2[1][1]%MOD)%MOD;
    p1[0][0] = tmp[0][0];
    p1[0][1] = tmp[0][1];
    p1[1][0] = tmp[1][0];
    p1[1][1] = tmp[1][1];
}

void metrixPow(int p[2][2], int n){
    int tmp[2][2];
    tmp[0][0] = p[0][0];
    tmp[0][1] = p[0][1];
    tmp[1][0] = p[1][0];
    tmp[1][1] = p[1][1];
    
    if(n==1) return ;
    else if((n&1)==1){//odd
        metrixPow(p, n-1);
        metrixMul(p, tmp);
    }
    else{
        metrixPow(p,n/2);
        metrixMul(p, p);// mind : means metrix p*p
    }
}
int main(){
    while(scanf("%d %d %d %d %d",&a0,&a1,&p,&q,&k)!=EOF){
        if(0==k){
            printf("%d\n",a0%MOD);
            continue;
        }
        if(1==k){
            printf("%d\n",a1%MOD);
            continue;
        }
        metrix[0][0] = p%MOD;
        metrix[0][1] = q%MOD;
        metrix[1][0] = 1;
        metrix[1][1] = 0;
        metrixPow(metrix, k-1);
        printf("%d\n",(metrix[0][0]*a1 + metrix[0][1]*a0)%MOD);
    }
    return 0;
}
