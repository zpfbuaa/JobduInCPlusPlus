//
//  1112 拦截导弹.cpp
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
#define MAX_SIZE 26

using namespace std;

int k;
int missile[MAX_SIZE];
int num[MAX_SIZE];

int main(){
    while(scanf("%d",&k)!=EOF){
        for(int i = 0 ; i < k; i++){
            scanf("%d",&missile[i]);
            num[i]=1;
        }
        int ans = 1;
        for(int i = 0 ; i < k ; i++){
            for(int j = 0 ; j < i ; j++){
                if(missile[j]>=missile[i]){
                    num[i]=max(num[i],num[j]+1);
                }
            }
            ans = max(ans,num[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
