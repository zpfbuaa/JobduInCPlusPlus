//
//  1003 A+B.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 2017/4/14.
//  Copyright © 2017年 PengFei_Zheng. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

char a[21],b[21];
int num1,num2;

int main(){
    while(scanf("%s%s",a,b)!=EOF){
        int lena = (int)strlen(a);
        int lenb = (int)strlen(b);
        num1 = num2 = 0;
        int size1 = 0;
        int size2 = 0;
        bool flag1 = (a[0]>='0'&&a[0]<='9') ? true : false;
        bool flag2 = (b[0]>='0'&&b[0]<='9')? true : false;
        for(int i = lena -1 ; i >= 0 ; i--){
            if(a[i]>='0' && a[i]<='9'){
                num1+=(a[i]-'0')*pow(10,size1);
                size1++;
            }
        }
        for(int i = lenb -1 ; i >= 0 ; i--){
            if(b[i]>='0' && b[i]<='9'){
                num2+=(b[i]-'0')*pow(10,size2);
                size2++;
            }
        }
        if(flag1&&flag2) printf("%d\n",num1+num2);
        else if(flag1 && !flag2) printf("%d\n",num1-num2);
        else if(flag2 && !flag1) printf("%d\n",num2-num1);
        else if(!flag1 && !flag2) printf("%d\n",0-num1-num2);
    }
}
