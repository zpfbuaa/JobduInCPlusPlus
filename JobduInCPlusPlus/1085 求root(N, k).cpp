//
//  1085 求root(N, k).cpp
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
#define L long long
using namespace std;

L cal(L x, L y, L k){
    L ans = 1;
    while(y!=0){
        if((y&1)==1){
            ans = (ans*x)%k;
        }
        x=(x*x)%k;
        y=y>>1;
    }
    return ans;
}
L x, y, k, ans;

int main(){
    while(scanf("%lld %lld %lld",&x,&y,&k)!=EOF){
        ans = cal(x,y,k-1);
        if(0 == ans)
            ans = k - 1;
        printf ("%lld\n", ans);
    }
    return 0;
}
