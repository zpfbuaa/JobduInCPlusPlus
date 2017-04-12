//
//  1440 Goldbach's Conjecture.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 12/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

bool isPrime(long long  n){// here n is no less than 4, so we don't need to consider 2、3
    long long  x = sqrt(n)+1;
    for(long long  i = 2 ; i <= x ; i ++){
        if(0 == n % i) return false;
    }
    return true;
}

long long  n;

int main(){
    while(scanf("%lld",&n)!=EOF && n!=0){
        int counter = 0;
        // beacuse n is even, so 2 can never being included
        // in order to reduce the calculation numbers, just need to reverse to n/2
        // therefore start with 3 and i+=2
        for(int i = 3 ; i <= n/2 ; i+=2){
            if(isPrime(i) && isPrime(n-i)){
                counter++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
