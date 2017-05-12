//
//  1013 开门人和关门人.cpp
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
#define MAX_SIZE 21
#define MAX_HUMAN 110

using namespace std;

int n, m;

struct Sign{
    char id[MAX_SIZE];
    int comeH;
    int comeM;
    int comeS;
    int leftH;
    int leftM;
    int leftS;
};

int cmpOpenDoor(const void *a , const void *b){
    Sign *c = (Sign *)a;
    Sign *d = (Sign *)b;
    if(c->comeH != d->comeH){
        return c->comeH - d->comeH;
    }
    else if(c->comeM != d->comeH){
        return c->comeM - d->comeM;
    }
    else
        return c->comeS - d->comeS;
}

int cmpCloseDoor(const void *a , const void *b){
    Sign *c = (Sign *)a;
    Sign *d = (Sign *)b;
    if(c->leftH != d->leftH){
        return d->leftH - c->leftH;
    }
    else if(c->leftM != d->leftM){
        return d->leftM - c->leftM;
    }
    else {
        return d->leftS - c->leftS;
    }
}

Sign sign[MAX_HUMAN];

int main(){
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i = 0 ; i < m ; i++){
            scanf("%s %d:%d:%d %d:%d:%d",sign[i].id,&sign[i].comeH,&sign[i].comeM,&sign[i].comeS,&sign[i].leftH,&sign[i].leftM,&sign[i].leftS);
        }
        qsort(sign,m,sizeof(Sign),cmpOpenDoor);
        printf("%s ",sign[0].id);
        qsort(sign,m,sizeof(Sign),cmpCloseDoor);
        printf("%s\n",sign[0].id);
//        for(int i = 0 ; i < m ; i++){
//            printf("%s %d:%d:%d %d:%d:%d\n",sign[i].id,sign[i].comeH,sign[i].comeM,sign[i].comeS,sign[i].leftH,sign[i].leftM,sign[i].leftS);
//        }
    }
}



