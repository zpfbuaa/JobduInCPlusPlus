//
//  1099 后缀子串排序.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 05/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#define MAX_SIZE 1010
//#define debug

using namespace std;

char str[MAX_SIZE];

string s[MAX_SIZE];
int cmp(const void *a, const void *b){
    string *c = (string*)a;
    string *d = (string*)b;
    return strcmp(c->c_str(), d->c_str());
}
int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%s",str)!=EOF){
        int len = (int)strlen(str);
        string tmp(str);
        for(int i = 0 ; i < len ; i++){
            s[i]=tmp.substr(i,len-i);
        }
        qsort(s,len,sizeof(s[0]),cmp);
        for(int i = 0 ; i < len ; i++){
            printf("%s\n",s[i].c_str());
        }
    }
}
