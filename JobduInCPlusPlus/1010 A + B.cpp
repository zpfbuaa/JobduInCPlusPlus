//
//  1010 A + B.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 28/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

#include <stdio.h>
#include <string.h>
char arr[10][8] = { "zero","one","two","three","four","five","six","seven","eight","nine"};
int find(char* str) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(arr[i], str) == 0)
            return i;
    }
    return 0;
}
int main() {
    char temp[8];
    while (scanf("%s", temp) != EOF) {
        int a = find(temp);
        scanf("%s", temp);
        if (temp[0] != '+') {
            a = a * 10 + find(temp);
            scanf("%s", temp);
        }
        scanf("%s", temp);
        int b = find(temp);
        scanf("%s", temp);
        if (temp[0] != '=') {
            b = b * 10 + find(temp);
            scanf("%s", temp);
        }
        if(a==0 && b==0)
            break;
        printf("%d\n", a + b);
    }
    return 0;
}

