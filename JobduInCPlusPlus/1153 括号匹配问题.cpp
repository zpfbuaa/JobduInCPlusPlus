//
//  1153 括号匹配问题.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 08/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

stack<int> l;
char s[110];

int main(){
    while(scanf("%s",s)!=EOF){
        
        int len = (int)strlen(s);
        int flag[len];
        memset(flag,0,sizeof(flag));
        while(!l.empty())
            l.pop();
        for(int i = 0 ; i < len ; i++){
            if(s[i]=='(')
                l.push(i);
            else if(s[i]==')' && !l.empty()){
                int temp = l.top();
                l.pop();
                flag[i]=1;
                flag[temp]=1;
            }
        }
        printf("%s\n",s);
        for(int i = 0 ; i < len ; i++){
            if(s[i]=='('){
                if(flag[i]!=1)
                    printf("$");
                else
                    printf(" ");
            }
            else if(s[i]==')'){
                if(flag[i]!=1)
                    printf("?");
                else
                    printf(" ");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
