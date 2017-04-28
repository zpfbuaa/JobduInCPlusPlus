//
//  1016 火星A+B.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 28/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAX_PRIME 30
#define MAX_SIZE 26
//#define debug

using namespace std;

int prime[MAX_PRIME];

bool isPrime(int x){
    if(x<=1) return false;
    if(x==2) return true;
    int tmp = sqrt(x)+1;
    for(int i = 2 ; i <= tmp ; i++){
        if(x%i==0)
            return false;
    }
    return true;
}

void calPrime(){
    int num = 0;
    for(int i = 2 ; num<25 ; i++){
        if(isPrime(i)){
            num++;
            prime[num] = i;
        }
    }
}

int a[MAX_SIZE];
int b[MAX_SIZE];
int sum[MAX_SIZE];
char c;
int lena, lenb, i, j;

void init(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    c=' ';
    lena=lenb=i=j=0;
}
int main(){
    calPrime();
#ifdef debug
    for(int i = 1 ; i < MAX_PRIME ; i++){
        cout<<i<<" is : "<<prime[i]<<endl;
    }
#endif
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    while(1){
        init();
        char c;
        
        for(i = 1 ; i < MAX_SIZE ; i++){
            scanf("%d",&a[i]);
            scanf("%c",&c);
            if(c==' ')break;
        }
        lena = i;
        for(j = 1 ; j < MAX_SIZE ; j++){
            scanf("%d",&b[j]);
            scanf("%c",&c);
            if(c=='\n')break;
        }
        lenb = j;
        if(a[1]==0 && b[1]==0)
            break;
        
        int maxLen = lena>=lenb ? lena : lenb;
        
        int carry=0;
        int len = maxLen;
        int x,y;
        for(i = 1 ; i <= maxLen; i++){
            if(lena>=1) x=a[lena--];
            else x=0;
            if(lenb>=1) y=b[lenb--];
            else y=0;
            sum[len--]=(x+y+carry)%prime[i];
            carry=(x+y+carry)/prime[i];
        }
        if(carry!=0){
            printf("%d,",carry);
        }
        for(i = 1 ; i < maxLen ; i++){
            printf("%d,",sum[i]);
        }
        printf("%d\n",sum[maxLen]);
    }
    return 0;
}



