//
//  1198 a+b.cpp
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

using namespace std;

char a[1010], b[1010], c[1010];

int main(){
    while(scanf("%s %s",a,b)!=EOF){
        int lena = (int)strlen(a);
        int lenb = (int)strlen(b);
        int i, j;
        int carry, len, tmp;
        carry = len = tmp = 0;
        
        for(i = lena-1, j = lenb-1; i >= 0 && j >= 0; i--, j--){
            tmp = a[i]-'0' + b[j]-'0' +carry;
            c[len++] = tmp%10;
            carry = tmp/10;
        }
        
        while(i >= 0){
            tmp = carry + a[i] - '0';
            c[len++] = tmp%10;
            carry = tmp/10;
            i--;
        }
        
        while(j >= 0 ){
            tmp = carry + b[j] - '0';
            c[len++] = tmp%10;
            carry = tmp/10;
            j--;
        }
        
        if(carry!=0){
            c[len++] = carry;
        }
        
        len--;
        for(; len>=0; len--){
            printf("%d",c[len]);
        }
        printf("\n");
    }
    return 0;
}
