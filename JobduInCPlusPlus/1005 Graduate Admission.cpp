//
//  1005 Graduate Admission.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 27/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define CHOOSE 6
#define MAX_SIZE 40001
#define SCHOOL 101

using namespace std;

int n, m, k ;

struct Apply{
    int ge;
    int gi;
    double gf;
    int choose[CHOOSE];
    int id;
    bool operator < (const Apply &A) const{
        if(gf != A.gf){
            return gf > A.gf;
        }
        else if(ge != A.ge){
            return ge > A.ge;
        }
        else {
            return ge > A.ge;
        }
    }
};
struct School{
    int quota;
    int realNum;
    int appid[MAX_SIZE];
};

Apply apply[MAX_SIZE];
School school[SCHOOL];

int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        
        for(int i = 0 ; i < m ; i++){
            scanf("%d",&school[i].quota);
            school[i].realNum=0;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d",&apply[i].ge,&apply[i].gi);
            
            apply[i].gf=(double)(apply[i].ge+apply[i].gi)/2.0;
            
            for(int j = 0 ; j < k ; j++){
                scanf("%d",&apply[i].choose[j]);
            }
            apply[i].id=i;
        }
        sort(apply,apply+n);
        int sid;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < k ; j++){
                sid = apply[i].choose[j];
                if(school[sid].quota > 0){
                    school[sid].appid[school[sid].realNum] = i;
                    school[sid].realNum++;
                    school[sid].quota--;
                    break;
                }
                else{
                    int lastid = school[sid].appid[school[sid].realNum-1];
                    if(apply[i].gf == apply[lastid].gf && apply[i].ge == apply[lastid].ge){
                        school[sid].appid[school[sid].realNum]=i;
                        school[sid].realNum++;
                        school[sid].quota--;
                        break;
                    }
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < school[i].realNum ; j++){
                school[i].appid[j] = apply[school[i].appid[j]].id;
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            if(school[i].realNum==0){
                printf("\n");
            }
            else if(school[i].realNum==1){
                printf("%d\n",school[i].appid[0]);
            }
            else{
                sort(school[i].appid,school[i].appid+school[i].realNum);
                bool first = true;
                for(int j = 0 ; j < school[i].realNum ; j++){
                    if(first==true){
                        first = false;
                    }
                    else{
                        printf(" ");
                    }
                    printf("%d",school[i].appid[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}


