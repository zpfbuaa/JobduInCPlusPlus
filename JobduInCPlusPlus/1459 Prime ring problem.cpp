//
//  1459 Prime ring problem.cpp
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
#define PRIME 13
#define MAX_SIZE 21
using namespace std;

int n;
int ans[MAX_SIZE];
bool used[MAX_SIZE];

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool judge(int x){
    for(int i = 0 ; i < PRIME ; i++){
        if(prime[i]==x)
            return true;
    }
    return false;
}

void check(){
    if(!judge(ans[n]+ans[1])) return;
    for(int i = 1 ; i <= n ; i++){
        if(i!=1) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}

void DFS(int num){
    if(num>1){
        if(!judge(ans[num] + ans[num - 1])) return;
    }
    if(num==n){
        check();
        return;
    }
    for(int i = 2 ; i <= n ; i++){
        if(!used[i]){
            used[i] = true;
            ans[num+1] = i;
            DFS(num+1);
            used[i] = false;
        }
    }
}

int main(){
    int kase = 0;
    while(scanf("%d",&n)!=EOF){
        kase++;
        memset(used,false,sizeof(used));
        ans[1] = 1;
        used[1]=true;
        printf("Case %d:\n",kase);
        DFS(1);
        printf("\n");
    }
    return 0;
}
