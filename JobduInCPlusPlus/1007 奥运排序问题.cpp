//
//  1007 奥运排序问题.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 28/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
//#include <cstring>
#define MAX_SIZE 1010
#define RANK 1

using namespace std;

struct Country{
    int id;
    int goldMedal;
    int totalMedal;
    int human;
    double goldRatio;
    double totalRatio;
    int rankGold;
    int rankTotal;
    int rankGoldRatio;
    int rankTotalRatio;
};

Country country[MAX_SIZE];
Country cal[MAX_SIZE];

int n, m;

int cmpRankGold(const void* a, const void *b){
    return (*(Country*)b).goldMedal - (*(Country*)a).goldMedal;
}

int cmpRankTotal(const void* a, const void *b){
    return (*(Country*)b).totalMedal - (*(Country*)a).totalMedal;
}

int cmpRankGoldRatio(const void* a, const void *b){
    return (*(Country*)b).goldRatio - (*(Country*)a).goldRatio;
}

int cmpRankTotalRatio(const void* a, const void *b){
    return (*(Country*)b).totalRatio - (*(Country*)a).totalRatio;
}

int cmpId(const void* a, const void *b){
    return (*(Country*)a).id - (*(Country*)b).id;
}

int main(){
//    freopen("/Users/pengfei_zheng/Desktop/input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d%d",&country[i].goldMedal,&country[i].totalMedal,&country[i].human);
            
        }
        for(int i = 0 ; i < m ; i++){
            int tmpId;
            scanf("%d",&tmpId);
            cal[i] = country[tmpId];
            cal[i].goldRatio = (double)cal[i].goldMedal/(double)cal[i].human;
            cal[i].totalRatio = (double)cal[i].totalMedal/(double)cal[i].human;
            cal[i].id=i;
            cal[i].rankGold=cal[i].rankTotal=cal[i].rankGoldRatio=cal[i].rankTotalRatio=MAX_SIZE;
        }
        
        qsort(cal,m,sizeof(Country),cmpRankGold);
        int rank = 1;
        cal[0].rankGold = 1;
        for(int i = 1 ; i < m ; i++){
            if(cal[i].goldMedal!=cal[i-1].goldMedal){
                rank = i + 1;
            }
            cal[i].rankGold = rank;
        }
        
        qsort(cal,m,sizeof(Country),cmpRankTotal);
        rank = 1;
        cal[0].rankTotal = 1;
        for(int i = 1 ; i < m ; i++){
            if(cal[i].totalMedal!=cal[i-1].totalMedal){
                rank = i + 1;
            }
            cal[i].rankTotal = rank;
        }
        
        qsort(cal,m,sizeof(Country),cmpRankGoldRatio);
        rank = 1;
        cal[0].rankGoldRatio = 1;
        for(int i = 1 ; i < m ; i++){
            if(cal[i].goldRatio!=cal[i-1].goldRatio){
                rank = i + 1;
            }
            cal[i].rankGoldRatio = rank;
        }
        
        qsort(cal,m,sizeof(Country),cmpRankTotalRatio);
        rank = 1;
        cal[0].rankTotalRatio = 1;
        for(int i = 1 ; i < m ; i++){
            if(cal[i].totalRatio!=cal[i-1].totalRatio){
                rank = i + 1;
            }
            cal[i].rankTotalRatio = rank;
        }
        
        qsort(cal,m,sizeof(Country),cmpId);
        
        for(int i = 0 ; i < m ; i++){
//            cout<<cal[i].rankGold<<" "<<cal[i].rankTotal<<" "<<cal[i].rankGoldRatio<<" "<<cal[i].rankTotalRatio<<endl;
            int minRank = cal[i].rankGold;
            int rankChoose = RANK;
            if(cal[i].rankTotal < minRank){
                minRank = cal[i].rankTotal;
                rankChoose= RANK + 1;
            }
            if(cal[i].rankGoldRatio < minRank){
                minRank = cal[i].rankGoldRatio;
                rankChoose = RANK + 2;
            }
            if(cal[i].rankTotalRatio < minRank){
                minRank = cal[i].rankTotalRatio;
                rankChoose = RANK + 3;
            }
            printf("%d:%d\n",minRank,rankChoose);
        }
        printf("\n");
    }
    return 0;
}
