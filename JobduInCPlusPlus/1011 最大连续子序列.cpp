//
//  1011 最大连续子序列.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 28/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAX_SIZE 10010

using namespace std;

int k;
int a[MAX_SIZE];

int main(){
    while(scanf("%d",&k)!=EOF && k!=0){
        for(int i = 0 ; i < k ; i++){
            scanf("%d",&a[i]);
        }
        int sum = a[0], max = a[0];
        int left =0 , right = 0;
        int ansLeft = 0, ansRight = 0;
        int ansMax = max;
        for(int i = 1 ; i < k ; i++){
            if(sum < 0){
                sum = 0;
                left = right = i;
            }
            sum += a[i];
            right = i;
            if(sum > max){
                ansLeft = left;
                ansRight = right;
                max = sum;
                ansMax = max;
            }
        }
        if(ansMax < 0){
            printf("0 %d %d\n",a[0],a[k-1]);
        }
        else{
            printf("%d %d %d\n",ansMax,a[ansLeft],a[ansRight]);
        }
    }
}

