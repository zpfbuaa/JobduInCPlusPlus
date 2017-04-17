//
//  1208 10进制 VS 2进制.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 17/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 10010
#define FROM 10
#define TO 2

using namespace std;




int main(){
    char from[MAX_SIZE];
    while(scanf("%s",from)!=EOF){
        int len = (int)strlen(from);
        int size = 0;
        //进行初始化操作
        char to[MAX_SIZE];//逆序保存十进制数对应的二进制，正好是题目需要的逆置二进制
        int ans[MAX_SIZE];//保存最终计算结果
        
        while(true){//FROM 进制转为 TO 进制
            int i = 0;
            while(from[i]=='0' && i < len) i++;
            if(i == len) break;
            int remain = 0;
            for(; i < len ; i++){
                int tmp = from[i] - '0' + remain * FROM;
                from[i] = tmp/TO+'0';
                remain = tmp%TO;
            }
            to[size++] = remain+'0';
        }
//        cout<<to<<endl;
        int length = 1;
        ans[0] = 0;//最内层为0*2 因此ans[0] = 0
        for(int i = 0; i < size ; i++){//1011 --> (((0*2+1)*2+0)*2+1)*2+1
            int carry = to[i] - '0';
            for(int j = 0 ; j < length ; j++){
                if(j==0)
                    ans[j] = ans[j] * TO + carry;//只需要加一次即可，也就在最低位加carry即可
                else
                    ans[j] = ans[j] * TO;
            }
            for(int j = 0 ; j < length ; j++){//进位操作
                if(j == length - 1 && ans[j] >=10){
                    ans[j] = ans[j]%10;
                    ans[++j] = 1;//这里最大的ans[j]=2*9+1 = 19因此进位只能是1
                    length++;
                }
                else if (ans[j]>=10){
                    ans[j] = ans[j]%10;
                    ans[j+1]++;//产生进位的只能是1
                }
            }
        }
        for(int i = length - 1 ; i >= 0 ; i--){
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

