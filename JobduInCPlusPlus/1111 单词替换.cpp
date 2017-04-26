//
//  1111 单词替换.cpp
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
#define MAX_SIZE 101

using namespace std;

int main(){
    string str, a, b;
    while(getline(cin,str)){
        getline(cin,a);
        getline(cin,b);
        int lenstr = (int)str.size();
        int lena = (int)a.size();
        int pos = (int)str.find(a,0);
        while(pos!=string::npos){//find the next a
            //to make sure that sting_a is a word beacuse before string_a is a space and after it is also a space
            if((pos!=0 && str[pos-1]!=' ') || (pos+lena < lenstr && str[pos+lena]!=' ')){
                pos = (int)str.find(a,pos+1);//start from the next pos
                continue;
            }
            str.replace(pos,lena,b);//start from pos and replace total length = lena and those position will be tooken by b
            pos = (int)str.find(a,pos+1);
        }
        cout<<str<<endl;
    }
    return 0;
}
