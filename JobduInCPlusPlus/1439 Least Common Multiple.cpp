//
//  1439 Least Common Multiple.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 10/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;
//to avoid overflow thus use long long to store data
long long  gcd(long long a, long long b){
    return b==0 ? a : gcd(b,a%b);
}

long long lcm(long long a, long long b){
    return (a/gcd(a,b))*b;// not a*b/gcd(a,b) beacuse it may cause overflow
}

int main(){
    int kase;
    scanf("%d",&kase);//kase number
    while(kase--){//a small tips
        int m;
        scanf("%d",&m);
        long long  ans;
        scanf("%lld",&ans);// input the first number
        for(int i = 1 ; i < m ; i++){
            long long tmp;//to store the next number
            scanf("%lld",&tmp);
            ans = lcm(ans,tmp);//calculate each two adjacent elements's lcm
        }
        printf("%lld\n",ans);//print the answer
    }
    return 0;
}
