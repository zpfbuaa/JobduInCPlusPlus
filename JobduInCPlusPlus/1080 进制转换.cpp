//
//  1080 进制转换.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 10/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int m,n;
char x[10010];

int main(){
    while(scanf("%d%d",&m,&n)!=EOF){// translate from m to n
        int from[10010]={0};//hold the numbers
        int to[10010]={0};//hold the answer
        scanf("%s",x);
        int len = (int)strlen(x);
        for(int i = 0; i < len ; i++){//change each position character to integer
            if(x[i]>='0' && x[i]<='9')
                from[i] = x[i]-'0';
            else
                from[i] = x[i]-'A'+10;
        }
        int size = 0;//record the length of answer number
        while(true){
            int i = 0 ;
            while(i<len&&from[i]==0)
                i++;
            if(i==len) break;
            int remain = 0;
            for(; i < len ; i++){
                int tmp = from[i] + remain * m ;
                from[i] = tmp/n;
                remain = tmp%n;
            }
            to[size++] = remain;
        }
        if(size==0) printf("%d\n",0);
        else {
            for(int i = size - 1 ; i >=0 ; i-- ){
                if(to[i]>9)
                    printf("%c",to[i]-10+'a');
                else
                    printf("%c",to[i]+'0');
            }
            printf("\n");
        }
    }
    return 0;
}
