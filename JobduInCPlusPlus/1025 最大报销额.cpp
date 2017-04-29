//
//  1025 最大报销额.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 29/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAX_SIZE 3001000
//#define debug
using namespace std;

double Q;
int N;
int q, m;

int pay[31];
int dp[MAX_SIZE];

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%lf%d",&Q,&N)!=EOF && N!=0){
        q = (int)(Q*100);
        int idx = 1;
        memset(pay,0,sizeof(pay));
        memset(dp,0,sizeof(dp));
        while(N--){
            int a, b, c;
            a = b = c  = 0;
            bool isLegal = true;
            scanf("%d",&m);
            for(int i = 1 ; i <= m ; i++){
                char type;
                double Price;
                int price;
                scanf(" %c:%lf",&type,&Price);
                price = (int)100*Price;
                if(type == 'A'){
                    a+=price;
                }
                else if(type == 'B'){
                    b+=price;
                }
                else if(type == 'C'){
                    c+=price;
                }
                else{
                    isLegal = false;
                }
                if(a+b+c>100000 || a > 60000 || b > 60000 || c > 60000){
                    isLegal = false;
                }
            }
            if(isLegal){
                pay[idx++]=a+b+c;
            }
        }
        for(int i = 1 ; i <= idx ; i++){
            for(int j = q ; j >= 1 ; j--){
                if(pay[i] <= j ){
                    dp[j] = max(dp[j],dp[j-pay[i]]+pay[i]);
                }
            }
        }
        printf("%.2lf\n",dp[q]/100.00);
    }
    return 0;
}
