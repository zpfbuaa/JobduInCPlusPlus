//
//  1104 整除问题.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 13/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int n, a;
int prime[1001];
bool mark[1001];
int primeSize;
int cnt1[1001],cnt2[1001];

void init() {
    primeSize = 0;
    memset(mark,false,sizeof(mark));
    for(int i = 2 ; i < 1001 ; i++) {
        if(mark[i]) continue;
        prime[primeSize++] = i;
        for(int j = i*i ; j < 1001 ; j +=i)
            mark[j] = true;
    }
}



int main(){
    init();
    while(scanf("%d%d",&n,&a)!=EOF){
        
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        
        for(int i = 0; i < primeSize ; i++){
            int tmp = n;
            while(tmp!=0){
                cnt1[i]+=tmp/prime[i];
                tmp/=prime[i];
            }
        }
        int ans = 100100100;
        for(int i = 0 ; i < primeSize ; i++){
            while(a%prime[i]==0){
                cnt2[i]++;
                a/=prime[i];
            }
            if (cnt2[i] == 0)
                continue;
            if(cnt1[i]/cnt2[i]<ans)
                ans =cnt1[i]/cnt2[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
