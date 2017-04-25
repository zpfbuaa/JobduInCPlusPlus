//
//  1453 Greedy Tino.cpp
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
#define MAX_SIZE 101
#define OFFSET 2000

using namespace std;

int t, n;
int weight[MAX_SIZE];
int dp[MAX_SIZE][4001];

int main(){
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        
        memset(weight, 0, sizeof(weight));
        scanf("%d",&n);
        bool haveZero = false;
        int num = 0;//weight is not zero
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&weight[++num]);
            if(weight[num]==0){
                num--;
                haveZero=true;
            }
            
        }
        n = num;
        for(int i = -2000 ; i <=2000 ; i++){
            dp[0][i+OFFSET]=-INT_MAX;
        }
        dp[0][0+OFFSET]=0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = -2000 ; j <= 2000 ; j++){
                int tmp = -INT_MAX;
                if(j+weight[i]<=2000 && dp[i-1][j+weight[i]+OFFSET]!=-INT_MAX){
                    tmp = dp[i-1][j+weight[i]+OFFSET]+weight[i];
                }
                if(j-weight[i]>=-2000 && dp[i-1][j-weight[i]+OFFSET]!=-INT_MAX){
                    tmp = max(tmp,dp[i-1][j-weight[i]+OFFSET]+weight[i]);
                }
                tmp = max(tmp,dp[i-1][j+OFFSET]);
                dp[i][j+OFFSET] = tmp;
            }
        }
        printf("Case %d: ",++kase);
        if(dp[n][0+OFFSET]==0){
            haveZero == true ? printf("0\n") : printf("-1\n");
        }
        else{
            printf("%d\n",dp[n][0+OFFSET]/2);
        }
    }
    return 0;
}
