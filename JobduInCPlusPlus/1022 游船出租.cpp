//
//  1022 游船出租.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 29/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#define MAX_SIZE 101

using namespace std;

struct Boat{
    int id;
    int start;
    int time;
    bool rent;
    Boat(){
        time = 0;
        rent = false;
    }
};

Boat boat[MAX_SIZE];
int num;
char key;
int hour,minute;
int rentCount;
double totalTime;

int main(){
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    while(scanf("%d",&num)!=EOF && num!=-1){
        rentCount = totalTime = 0;
        while(num != 0){
            scanf(" %c %d:%d",&key,&hour,&minute);
            if(key == 'S'){
                boat[num].id = num;
                boat[num].start = hour * 60 + minute;
                boat[num].rent = true;
            }
            else if(key == 'E'){
                if(boat[num].rent == true){
                    boat[num].time = (hour * 60 + minute) - boat[num].start;
                    rentCount++;
                    totalTime += boat[num].time;
                }
            }
            scanf("%d",&num);
        }
        scanf(" %c %d:%d",&key,&hour,&minute);
        if(rentCount!=0){
            printf("%d %.0f\n",rentCount,totalTime/rentCount);
        }
        else{
            printf("0 0\n");
        }
    }
}
