//
//  1089 数字反转.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 04/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int reverse(int x){
    int tmp = x;
    int ans = 0;
    while(tmp!=0){
        ans = ans*10 + tmp%10;
        tmp/=10;
    }
    return ans;
}
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        int sum = a+b;
        reverse(sum) == reverse(a) + reverse(b) ? printf("%d\n",sum) : printf("NO\n");
    }
}
