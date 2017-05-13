//
//  1014 排名.cpp
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
#define MAX_STUDENT 1001
#define MAX_PROBLEM 11
#define MAX_ID 22

using namespace std;



struct AC{
    char id[MAX_ID];
    int num;
    int problem[MAX_PROBLEM];
    int score;
};

int cmpScore(const void *a , const void *b){
    AC *c = (AC*)a;
    AC *d = (AC*)b;
    if(d->score!=c->score)
        return d->score - c->score;
    else
        return strcmp(c->id,d->id);
}

AC ac[MAX_STUDENT];
int n, m, g;

int grade[MAX_PROBLEM];

int main(){
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    while(scanf("%d",&n)!=EOF && n!=0){
        scanf("%d%d",&m,&g);
        for(int i = 1 ; i <= m ; i++){
            scanf("%d",&grade[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            scanf("%s %d",ac[i].id,&ac[i].num);
            ac[i].score = 0;
            for(int j = 1 ; j <= ac[i].num ; j++){
                scanf("%d",&ac[i].problem[j]);
                ac[i].score+=grade[ac[i].problem[j]];
            }
        }
        
        qsort(ac,n,sizeof(AC),cmpScore);
        int ans = 0;
        for(int i =0 ; i < n ; i ++){
            if(ac[i].score>=g){
                ans++;
            }
        }
        printf("%d\n",ans);
        for(int i = 0 ; i < n ; i++){
            if(ac[i].score>=g)
            printf("%s %d\n",ac[i].id,ac[i].score);
        }
    }
    return 0;
}
