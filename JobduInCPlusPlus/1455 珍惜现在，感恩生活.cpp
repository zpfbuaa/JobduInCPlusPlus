//
//  1455 珍惜现在，感恩生活.cpp
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
#define MAX_SIZE 101
#define MAX_NUM 2001
using namespace std;

int C, n, m, price, weight, num;

struct Rice{
    int price;
    int weight;
};

int dp[MAX_SIZE];
Rice rice[MAX_NUM];

int main(){
    scanf("%d",&C);//C means the number of total test cases
    while(C--){
        scanf("%d%d",&n,&m);// n means the money yout have, m means there are m different kinds of rice in market.
        int cnt = 0;//divide the rice into different heap
        for(int i = 1 ; i <= m ; i++){
            scanf("%d%d%d",&price,&weight,&num);//input each kind of rice's price, weight, num
            int x = 1;
            while(num-x>0){
                num-=x;
                cnt++;
                rice[cnt].price = x * price;
                rice[cnt].weight = x * weight;
                x*=2;
            }
            cnt++;
            rice[cnt].price = num * price;
            rice[cnt].weight = num * weight;
        }
        //initation the dp[j] means: with money j the total weight rice you can buy.
        for(int i = 1 ; i <= n ; i++){
            dp[i]=0;
        }
        //change the problem into 0-1 backpage
        for(int i = 1 ; i <= cnt ; i++){
            for(int j = n ; j >= rice[i].price ; j--){
                dp[j] = max(dp[j],dp[j-rice[i].price]+rice[i].weight);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

