//
//  1137 浮点数加法.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 16/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 1010
using namespace std;


struct fld{
    int p[MAX_SIZE];//整数部分（逆序存储）123. -->321.
    int q[MAX_SIZE];//小数部分（正序存储）.456 -->.456
    int pSize;//整数长度
    int qSize;//小数长度
    void init(){//初始化操作
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        pSize=0;
        qSize=0;
    }
    fld operator + (const fld &a)const{//重载加法运算符
        fld ret;//保存返回结果
        ret.init();
        int qLen = qSize > a.qSize ? qSize : a.qSize;//小数长度
        int carry = 0;//保存进位，以及小数到整数部分的进位
        ret.qSize = qLen;
        for(int i = qLen-1 ; i >= 0 ; i--){//小数部分相加
            int tmp = q[i]+a.q[i] + carry;
            ret.q[--qLen] = tmp%10;//保存结果
            carry = tmp/10;//更新进位
        }
        int pLen = pSize > a.pSize ? pSize : a.pSize;//整数长度
        for(int j = 0 ; j < pLen ; j++){//整数部分相加
            int tmp = p[j]+a.p[j] + carry;
            ret.p[ret.pSize++] = tmp%10;//保存结果
            carry = tmp/10;//更新进位
        }
        if(carry!=0){//当前进位不为0，进位并保存下来
            ret.p[ret.pSize++]=carry;
        }
        return ret;
    }
    void output(){
        int i = pSize - 1;
        while(p[i]==0 && i>=0 )i--;//移除高位的0
        if(i==-1){
            printf("0");
        }
        else{
            while(i>=0){//倒序输出整数部分
                printf("%d",p[i--]);
            }
        }
        int j = qSize - 1;
        while(q[j]==0 && j>=0) j--;//移除小数部分低位0,并保存小数部分有效长度
        if(j!=-1){
            printf(".");//打印小数点
            int k = 0;
            while(k <= j){//输出小数部分
                printf("%d",q[k++]);
            }
        }
        printf("\n");
    }
};

fld change(char s[]){
    fld tmp;
    tmp.init();
    int p;
    for(p = 0; s[p] != '.'; p ++);//定位小数点下标
    int len = (int)strlen(s);
    for(int i = p+1 ; i < len ; i++){//正序存储小数部分
        tmp.q[tmp.qSize++] = s[i]-'0';
    }
    for(int j = p-1; j >= 0 ; j--){//逆序存储整数部分
        tmp.p[tmp.pSize++] = s[j]-'0';
    }
    return tmp;
}

int n;
char A[MAX_SIZE],B[MAX_SIZE];

int main(){
    while(scanf("%d",&n)!=EOF){
        while(n--){
            scanf("%s%s",A,B);
            fld a,b,c;
            a.init();
            b.init();
            c.init();
            a = change(A);
            b = change(B);
            c = a+b;//使用重载的加法运算符
            c.output();//打印结果
        }
    }
}
