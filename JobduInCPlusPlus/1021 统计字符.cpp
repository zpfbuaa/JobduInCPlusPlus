//
//  1021 统计字符.cpp
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
#define STR_FIND 10
#define STR_LONG 88
using namespace std;

char strFind[STR_FIND];
int strNum[STR_FIND];
char str[STR_LONG];

int main(){
//    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
    while(cin.getline(strFind,STR_FIND)){
        if(strFind[0]=='#') break;
        memset(strNum,0,sizeof(strNum));
        
        int len = (int)strlen(strFind);
//        getchar();//加上这句就错了！
        cin.getline(str, STR_LONG);
        int maxLen = (int)strlen(str);
        for(int i = 0 ; i < maxLen ; i++){
            for(int j = 0 ; j < len ; j++){
                if(strFind[j]==str[i]){
                    strNum[j]++;
                    break;
                }
            }
        }
        
        for(int i = 0 ; i < len ; i++){
            printf("%c %d\n",strFind[i],strNum[i]);
        }
    }
    return 0;
}
