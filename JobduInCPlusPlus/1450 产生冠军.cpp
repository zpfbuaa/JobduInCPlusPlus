//
//  1450 产生冠军.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 21/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <map>
#define MAX_SIZE 2017

using namespace std;

map<string,int> name2id;
int inDegree[MAX_SIZE];

int n;

int main(){
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i = 1 ; i <= 2*n ; i++){
            inDegree[i]=0;
        }
        while(!name2id.empty()) name2id.clear();
        string a, b;
        int num = 0;
        while(n--){
            cin>>a>>b;
            if(!name2id.count(a)){
                num++;
                name2id.insert(make_pair(a, num));
            }
            if(!name2id.count(b)){
                num++;
                name2id.insert(make_pair(b, num));
            }
            int id_b = name2id[b];
            inDegree[id_b]++;
        }
        int ans = 0;
        for(int i = 1 ; i <= num ; i++){
            if(inDegree[i]==0)
                ans++;
        }
        ans == 1 ? printf("Yes\n") : printf("No\n");
    }
}
