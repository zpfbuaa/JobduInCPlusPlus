//
//  1095 2的幂次方.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 05/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;


void print(int n){
    if(n==1) return;
    if(n==0){
        printf("0");
        return;
    }
    bool first = true;
    for(int i = 31 ; i >= 0 ; i--){
        if(((n>>i)&1)==1){//find the hightest pos
            if(first){
                first = false;
            }
            else {
                printf("+");
            }
            printf("2");
            if(i!=1){
                printf("(");
            }
            print(i);
            if(i!=1){
                printf(")");
            }
        }
    }
}
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        print(n);
        printf("\n");
    }
    return 0;
}
