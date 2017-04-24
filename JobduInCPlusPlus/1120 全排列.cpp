//
//  1120 全排列.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 23/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 7

using namespace std;

char str[MAX_SIZE];
char ans[MAX_SIZE];
bool used[MAX_SIZE];
int len;

void prem(int x){
    if(x == len){
        ans[x]='\0';
        printf("%s\n",ans);
        return;
    }
    for(int i = 0 ; i < len ; i++){
        if(!used[i]){
            used[i] = true;
            ans[x] = str[i];
            prem(x+1);
            used[i]=false;
        }
    }
}
int main(){
    while(scanf("%s",str)!=EOF){
        memset(used,false,sizeof(used));
        len = (int)strlen(str);
        prem(0);
        printf("\n");
    }
    return 0;
}
