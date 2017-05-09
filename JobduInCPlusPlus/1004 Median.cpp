//
//  1004 Median.cpp
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
#define MAX_SIZE 2000002
using namespace std;

int a[MAX_SIZE];

int n, m;

int cmp(void const *a,  void const *b){
    return *(int *)a - *(int *)b;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(int i = n ; i < n+m ; i++){
            scanf("%d",&a[i]);
        }
        qsort(a,n+m,sizeof(a[0]),cmp);
        printf("%d\n",a[(n+m-1)/2]);
    }
    return 0;
}
