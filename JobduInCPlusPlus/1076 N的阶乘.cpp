//
//  1076 N的阶乘.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 16/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 10010
using namespace std;

int n;
int pos[MAX_SIZE];

int main(){
    while(~scanf("%d",&n)){
        memset(pos,0,sizeof(pos));
        if(0==n){//tips: 0! = 1
            printf("1\n");
            continue;
        }
        int i,j;
        int length = 1;//hold the length of answer
        pos[0]=1;
        for(i = 1 ; i <= n ; i++){
            int carry = 0;
            for(j = 0 ; j < length ; j++){
                pos[j] = pos[j] * i + carry;// multiply each number
                if(pos[j]>=10){//carry
                    carry = pos[j]/10;
                    pos[j] = pos[j]%10;
                }
                else{//init carry
                    carry = 0;
                }
            }
            while(carry!=0){//add each osition carry to pos array
                pos[length++] = carry % 10;
                carry/=10;
            }
        }
        for(j = length-1 ; j >= 0 ; j--){//print the answer
            printf("%d",pos[j]);
        }
        printf("\n");
    }
    return 0;
}
