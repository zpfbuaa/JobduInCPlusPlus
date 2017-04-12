//
//  1040 Prime Number.cpp
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
#define max_size 1000010
using namespace std;

bool prime[max_size];


void init(){
    memset(prime,1,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
    int x = sqrt(max_size) + 1 ;
    
    for(int i = 2; i < x ; i++){
        
        if(prime[i] == true ){
            for(int j = i + i ; j < max_size ; j += i)
                prime[j] = false ;
        }
    }
}

int main(){
    init();
    int k;
    while(scanf("%d",&k)!=EOF){
        int nums = 0 ;
        for(int i = 0 ; i < max_size ; i ++){
            if(prime[i] == true){
                nums++;
                if(nums==k){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
