//
//  1029 魔咒词典.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 30/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#define MAX_SIZE 110
//#define debug
using namespace std;

map<string,string> myMap;

char s[MAX_SIZE];
string str;
string curse;
string fun;
int n;

int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(gets(s)){
        str = s;
        if(str=="@END@") break;
        int len = (int)str.size();
        int i;
        for(i = 0 ; i < len ; i ++){
            if(str[i]==']')
                break;
        }
        curse = str.substr(0,i+1);
        fun = str.substr(i+2,len);
        myMap[curse]=fun;
        myMap[fun]=curse;
    }
    scanf("%d\n",&n);
    while(n--){
        gets(s);
        str = s;
        if(myMap.count(s)==0){
            printf("what?\n");
        }
        else{
            string tmp = myMap[str];
            if(tmp[0]=='['){
                tmp = tmp.substr(1,tmp.length()-2);
            }
            printf("%s\n",tmp.c_str());
        }
    }
    return 0;
}
