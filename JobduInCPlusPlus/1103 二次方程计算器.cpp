//
//  1103 二次方程计算器.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 07/05/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <cmath>
#include <climits>
#include <stack>
#define MAX_SIZE 101
//#define debug

using namespace std;

int leftA, rightA;
int leftB, rightB;
int leftC, rightC;

char equation[1001];

void init(){
    leftA = rightA = 0;
    leftB = rightB = 0;
    leftC = rightC = 0;
}

void cal(string str, int &a, int &b, int &c){
    int len = (int)str.size();
    int i = 0;
    for( ; i < len ; i++){
        if(str[i]=='+') continue;
        else if(str[i]=='-'){//不操作，可能为负系数
        }
        else if(str[i]=='x'){// a或者b的系数为1或者-1
            if(i+1 < len && str[i+1]=='^'){
                if(i-1>=0 && str[i-1]=='-'){
                    a-=1;
                }
                else{
                    a+=1;
                }
                i+=3;//由于x^2 占3个字符，因此更新为i+=3
            }
            else{
                if(i-1>=0 && str[i-1]=='-'){
                    b-=1;
                }
                else{
                    b+=1;
                }
                i+=1;//x占1个字符，因此更新为i+=1
            }
        }
        else{//a,b系数不为1或者-1，但可能为负数 c为常数
            int tmp = 0;
            int j = i;//保存进入时的位置，用于判断是否为负数
            while(isdigit(str[i])){//数字
                tmp = tmp*10 + str[i]-'0';
                i++;
            }
            if(j-1>=0 && str[j-1] == '-'){//获取得到负数
                tmp = 0 - tmp;
            }
            if(i < len && str[i]=='x'){
                if(i+1<len && str[i+1]=='^'){
                    a+=tmp;
                    i+=3;//同上 x^2 占3个字符 --> i+=3
                }
                else{
                    b+=tmp;
                    i+=1;
                }
            }
            else{
                c+=tmp;//更新常数
            }
        }
    }
}
int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%s",equation)!=EOF){
        string s(equation);
        int len = (int)s.size();
        int idx = 0;
        for(int i = 0 ; i < len ; i++){
            if(s[i]=='='){
                idx = i;
                break;
            }
        }
        init();
        string strLeft = s.substr(0,idx);
        string strRight = s.substr(idx+1);
        cal(strLeft,leftA,leftB,leftC);
        cal(strRight,rightA,rightB,rightC);
        int a = leftA - rightA;
        int b = leftB - rightB;
        int c = leftC - rightC;
        int tmp = b*b - 4*a*c;
        if(tmp<0){
            printf("No Solution\n");
        }
        else{
            double x1,x2;
            x1 = (double)(0-b+sqrt(tmp))/(2*a);
            x2 = (double)(0-b-sqrt(tmp))/(2*a);
            if(x1<x2){
                printf("%.2lf %.2lf\n",x1,x2);
            }
            else {
                printf("%.2lf %.2lf\n",x2,x1);
            }
        }
    }
    return 0;
}
