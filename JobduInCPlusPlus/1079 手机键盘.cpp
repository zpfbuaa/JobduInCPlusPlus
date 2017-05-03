//
//  1079 手机键盘.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 03/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>
#define MAX_SIZE 110

using namespace std;

char str[MAX_SIZE];
int pos[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int kase[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main(){
    while(scanf("%s",str)!=EOF){
        int len = (int)strlen(str);
        int sum = kase[str[0]-'a'];
        for(int i = 1 ; i < len ; i++){
            if(pos[str[i]-'a']!=pos[str[i-1]-'a']){
                sum+=(kase[str[i]-'a']);
            }
            else {
                sum+=2+kase[str[i]-'a'];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
