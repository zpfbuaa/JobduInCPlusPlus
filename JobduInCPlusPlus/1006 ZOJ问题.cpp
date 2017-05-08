//
//  1006 ZOJ问题.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 28/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 1001

using namespace std;

string str;

bool judge(){
    int idxZ = -1 ;
    int idxJ = -1 ;
    bool zoj = true;
    int len = (int)str.size();
    for(int i = 0 ; i < len ; i++){
        if(str[i]=='z' && idxZ == -1){
            idxZ = i;
        }
        else if(str[i]=='j' && idxJ == -1){
            idxJ = i;
        }
        else if(str[i]!='o'){
            zoj = false;
        }
    }
    int a = idxZ;
    int b = idxJ - idxZ -1;
    int c = len - 1 - idxJ;
    if(zoj && idxZ != -1 && idxJ != -1 && (idxZ +1 < idxJ) && a*b==c){
        return true;
    }
    else return false;
}
int main(){
    while(cin>>str){
        if(judge()){
            printf("Accepted\n");
        }
        else{
            printf("Wrong Answer\n");
        }
    }
}
