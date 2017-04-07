//
//  1019 简单计算器.cpp
//  oj
//
//  Created by PengFei_Zheng on 04/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stack>

#define run ;
//#define debug ;

using namespace std;
int num1;
double temp;

stack<double> myStack;

int main(){

#ifdef debug
    while(scanf("%d ",&num1)&&num1!=0){
        cout<<num1<<" ";
        char a,b;
        int num;
        while(scanf("%c %d%c",&a,&num,&b)!=EOF){
            if(b!=' '){
                cout<<a<<" "<<num<<endl;
                break;
            }
            else{
                cout<<a<<" "<<num<<b;
            }
        }
    }
#endif
    
#ifdef run
    char space0;
    while(scanf("%d%c",&num1,&space0)&&num1!=0&&space0==' '){//ignore the space and using space0!=' ' and num1==0 the jump out of loop
        while(!myStack.empty()){
            myStack.pop();
        }
        myStack.push(num1);
//        cout<<"myStack push: "<<num1<<endl;
        char op,space1,space2;
        int num2;
        
        while(scanf("%c%c%d%c",&op,&space1,&num2,&space2)!=EOF){//ignore the space and using space2 to jump out of this calculation
            if(op=='+'){
//                cout<<"myStack push: "<<num2<<endl;
                myStack.push(num2);
            }
            else if(op=='-'){
//                cout<<"myStack push: "<<0-num2<<endl;
                myStack.push(0-num2);
            }
            else if(op=='*'){
                temp = myStack.top();
                myStack.pop();
//                cout<<"myStack push: "<<temp*num2<<endl;
                myStack.push(temp*num2);
            }
            else if(op=='/'){
                temp = myStack.top();
                myStack.pop();
//                cout<<"myStack push: "<<temp/num2<<endl;
                myStack.push(temp/num2);
            }
            if(space2!=' ')//jump out of loop
                break;
        }
        while(!myStack.empty()){
            if(myStack.size()==1){
                printf("%.2lf\n",myStack.top());
                break;
            }
            double x = myStack.top();
            myStack.pop();
            double y = myStack.top();
            myStack.pop();
            myStack.push(x+y);
        }
    }
#endif
    
}
