//
//  1442 A sequence of numbers.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 15/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define ret 200907
using namespace std;

int n;
long long a,b,c,k;

long long cal(long long a, long long q, long long  k){
    long long ans = a;
    k--;
    while(k!=0){
        if(k%2==1){
            ans *= q;
            ans%=ret;
        }
        k/=2;
        q*=q;
        q%=ret;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        long long ans = 0;
        if(b-a==c-b){
            ans=( a % ret )+( ( (k-1)%ret )*( (b-a)%ret )%ret )%ret;
        }
        else{
            long long  q = b/a;
            ans = cal(a,q,k);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
