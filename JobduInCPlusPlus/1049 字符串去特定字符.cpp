//
//  1049 字符串去特定字符.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 26/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 10010

using namespace std;

char str[MAX_SIZE];

int main(){
    while(scanf("%s",str)!=EOF){
        char c;
        cin>>c;
        int len = (int)strlen(str);
        for(int i = 0 ; i < len ; i++){
            if(str[i]!=c){
                cout<<str[i];
            }
        }
        cout<<endl;
    }
    
}


