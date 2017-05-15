//
//  1018.cpp
//  oj
//
//  Created by PengFei_Zheng on 05/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//
//ios::sync_with_stdio(false);

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n,temp,grade;
int score[101]={0};

int main(){

    while(scanf("%d",&n)&&n!=0){
        memset(score,0,sizeof(score));
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&temp);
            score[temp]++;
        }
        scanf("%d",&grade);
        printf("%d\n",score[grade]) ;
    }
}
