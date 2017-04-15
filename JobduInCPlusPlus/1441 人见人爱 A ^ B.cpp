//
//  1441 人见人爱 A ^ B.cpp
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

using namespace std;

int a,b;


int main(){
    while(scanf("%d%d",&a,&b)!=EOF){
        if(0==a && 0==b) break;//a==0 && b==0 means the ending of program
        int ans = 1;//keep the answer
        while(b!=0){//transfer to binary
            if(b%2==1){//this pos is 1
                ans *= a;
                ans%=1000;
            }
            b/=2;
            a*=a;
            a%=1000;
        }
        printf("%d\n",ans);
    }
    return 0;
}
