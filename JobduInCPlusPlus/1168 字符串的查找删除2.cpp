//
//  1168 字符串的查找删除2.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 25/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 1001

using namespace std;

char str[MAX_SIZE];

int main(){
    gets(str);
    string a = str;
    int lena = (int)a.size();
    for(int i = 0 ; i < lena ; i++){
        a[i] = tolower(a[i]);
    }
    while(gets(str)){
        string b = str;
        string c = b;
        int lenb = (int)b.size();
        for(int i = 0 ; i < lenb ; i++){
            b[i]=tolower(b[i]);
        }
        int pos = (int)b.find(a,0);
        while(pos!=string::npos){
            c.erase(pos,lena);
            b.erase(pos,lena);
            pos = (int)b.find(a,pos);
        }
        pos = (int)c.find(' ',0);
        while(pos!=string::npos){
            c.erase(pos,1);
            pos = (int)c.find(' ',0);
        }
        cout<<c<<endl;
    }
    return 0;
}
