//
//  1161 Repeater.cpp
//  oj
//
//  Created by PengFei_Zheng on 05/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <stdlib.h>
#include <cmath>

using namespace std;

int n,q;
char buf[3001][3001];
char sample[3001][3001];
char board[6][6];

void init(int a, int b, int n){
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            buf[a * n + i][b * n + j]=' ';
        }
    }
}

void copy(int a, int b, int n){
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            buf[a * n + i][b * n + j] = sample[i][j];
        }
    }
}

void update(int n){
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            sample[i][j]=buf[i][j];
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF&&n!=0){
        getchar();
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                scanf("%c",&buf[i][j]);
                board[i][j]=buf[i][j];
            }
            getchar();
        }
        scanf("%d",&q);
        int size = n ;
        for(int k = 2 ; k <= q ; k++){
            update(size);
            for(int i = 0 ; i < n ; i++){
                for(int j = 0; j < n ; j++){
                    if(board[i][j]==' ')
                        init(i,j,size);
                    else
                        copy(i,j,size);
                }
            }
            size = pow(n,k);
        }
        for(int i = 0 ; i < size ; i ++){
            for(int j = 0 ; j < size ; j ++){
                printf("%c",buf[i][j]);
            }
            cout<<endl;
        }
    }
    return 0;
}
