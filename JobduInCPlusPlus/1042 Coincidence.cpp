//
//  1042 Coincidence.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 24/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define MAX_SIZE 101

using namespace std;

char a[MAX_SIZE];
char b[MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int main(){
    while(scanf("%s%s",a,b)!=EOF){
        int lena = (int)strlen(a);
        int lenb = (int)strlen(b);
        for(int i = 0 ; i <= lena ; i++){
            dp[i][0] = 0;
        }
        for(int j = 0 ; j <= lenb ; j++){
            dp[0][j] = 0;
        }
        for(int i = 1 ; i <= lena ; i++){
            for(int j = 1 ; j <= lenb ; j++){
                if(a[i-1]!=b[j-1]){
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                else{
                    dp[i][j] = dp[i-1][j-1]+1;
                }
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
