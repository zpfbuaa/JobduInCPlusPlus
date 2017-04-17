//
//  1012 畅通工程.cpp
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
#define MAX_SIZE 1010

using namespace std;

int n, m;
int Tree[MAX_SIZE];

int findRoot(int x){//find the root of x
    if(Tree[x]==-1) return x;
    else{
        int tmp = findRoot(Tree[x]);//continue the find
        Tree[x] = tmp;//change the root of x to tmp
        return tmp;
    }
    
}
int main(){
    while(scanf("%d",&n)!=EOF && n!=0){//when n==0 and jump out of the loop
        scanf("%d",&m);
        for(int i = 1 ; i <= n ; i++)//init
            Tree[i] = -1;
        
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            a = findRoot(a);//find the root of a
            b = findRoot(b);//find the root of b
            if(a!=b) Tree[a]=b;//merge those two sets to the same aggregates
        }
        
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(Tree[i]==-1) ans++;//calculate the total numbers of aggregates
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
