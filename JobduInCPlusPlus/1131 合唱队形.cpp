//
//  1131 合唱队形.cpp
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
#define MAX_SIZE 101

using namespace std;

int n;
int height[MAX_SIZE];
int l2r[MAX_SIZE];
int r2l[MAX_SIZE];

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 0 ; i < n ; i ++){
            scanf("%d",&height[i]);
            l2r[i]=1;
            r2l[i]=1;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(height[i]>height[j]){
                    l2r[i]=max(l2r[i],l2r[j]+1);
                }
            }
        }
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = n-1 ; j > i ; j--){
                if(height[i]>height[j]){
                    r2l[i]=max(r2l[i],r2l[j]+1);
                }
            }
        }
        int ans = 1;
        for(int i = 0 ; i < n ; i ++){
            ans = max(ans,l2r[i]+r2l[i]-1);//l2r + r2l - 1 means the max number which suit ta<tb<..< tmax >...ti>tj
        }
        ans = n - ans;//find the least number need to be removed
        printf("%d\n",ans);
    }
    return 0;
}

