//
//  1454 Piggy-Bank.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 25/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <limits.h>
#define MAX_SIZE 10001
#define MAX_NUM 501

using namespace std;

struct Coin{
    int value;
    int space;
};

int t, e, f, n;
int dp[MAX_SIZE];
Coin coin[MAX_NUM];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        int space = f - e;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d",&coin[i].value,&coin[i].space);
        }
        for(int i = 0 ; i <= space ; i++){
            i == 0 ? dp[i] = 0 : dp[i] = INT_MAX;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = coin[i].space ; j <= space ; j++){
                if(dp[j-coin[i].space] != INT_MAX)
                    dp[j] = min(dp[j], dp[j-coin[i].space]+coin[i].value);
            }
        }
        if(dp[space] != INT_MAX)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[space]);
        else
            printf("This is impossible.\n");
    }
    return 0;
}
