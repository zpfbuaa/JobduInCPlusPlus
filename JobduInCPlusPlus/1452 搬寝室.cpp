//
//  1452 搬寝室.cpp
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
#include <limits.h>
//#define MAX 0x7fffffff
#define MAX_SIZE 2001
#define MAX_ROW 1001
using namespace std;

int n, k;

int weight[MAX_SIZE];
long long dp[MAX_ROW][MAX_SIZE];

int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&weight[i]);
        }
        sort(weight+1,weight+1+n);
        for(int i = 1 ; i <= n ; i++){
            dp[0][i]=0;
        }
        for(int i = 1 ; i <= k ; i++){
            for(int j = 2*i ; j <= n ; j++){
                if(j>2*i){
                    dp[i][j] = dp[i][j-1];//暂时设为和之前一样（默认不选择j）
                }
                else
                    dp[i][j] = INT_MAX;
                
                if(dp[i][j] > dp[i-1][j-2]+pow(weight[j]-weight[j-1],2)){//判断选择j好还是不选择好
                    dp[i][j] = dp[i-1][j-2]+pow(weight[j]-weight[j-1],2);
                }
            }
        }
        printf("%lld\n",dp[k][n]);
    }
    return 0;
}
