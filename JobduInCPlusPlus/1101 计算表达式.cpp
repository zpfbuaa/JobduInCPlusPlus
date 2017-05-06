//
//  1101 计算表达式.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 06/05/2017.
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


using namespace std;

stack<int> myStack;

int main(){
    int firstNum;
    while(scanf("%d",&firstNum)!=EOF){
        while(!myStack.empty()) {
            myStack.pop();
        }
        myStack.push(firstNum);
        char op;
        while(scanf("%c",&op)!=EOF && op!='\n'){
            int nextNum;
            scanf("%d",&nextNum);
            switch(op){
                case '+':{
                    myStack.push(nextNum);
                    break;
                }
                case '-':{
                    myStack.push(0-nextNum);
                    break;
                }
                case '*':{
                    int tmp1 = myStack.top();
                    myStack.pop();
                    myStack.push(tmp1*nextNum);
                    break;
                }
                case '/':{
                    int tmp2 = myStack.top();
                    myStack.pop();
                    myStack.push(tmp2/nextNum);
                    break;
                }
                default:
                    break;
            }
        }
        
        int ans = 0;
        while(!myStack.empty()){
            int tmp = myStack.top();
            ans += tmp;
            myStack.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}



