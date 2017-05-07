//
//  1102 最小面积子矩阵.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 07/05/2017.
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
#define MAX_SIZE 101
#define debug


using namespace std;

int n, m, k;
int ans;

int metrix[MAX_SIZE][MAX_SIZE];
int line[MAX_SIZE];

int cal(int m){
    int ans = -1;
    int begin = 0, over = 0 , sum = 0;
    while(over < m){
        if(sum < k){
            sum+=line[over];
        }
        while(sum >= k){
            int len = over - begin + 1;
            if(-1 == ans) {
                ans = len;
            }
            else if(len < ans){
                ans = len;
            }
            sum-=line[begin];
            begin++;
        }
        over++;
    }
    return ans;
}
int main(){
#ifdef debug
    freopen("/Users/pengfei_zheng/Desktop/input.txt", "r", stdin);
#endif
    while(scanf("%d %d %d",&n,&m,&k)!=EOF){
        ans = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                scanf("%d",&metrix[i][j]);
            }
        }
        for(int i = 0 ; i < n ; i++){
            memset(line,0,sizeof(line));
            for(int k = i ; k < n ; k++){
                for(int j = 0 ; j < m ; j++){
                    line[j]+=metrix[k][j];
                }
                int tmp = cal(m);
                if(tmp!=-1){
                    tmp = tmp * (k - i + 1);
                    if(-1 == ans){
                        ans = tmp;
                    }
                    else if(tmp < ans) ans = tmp;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
