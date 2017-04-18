//
//  1446 Head of a Gang.cpp
//  Jobdu
//
//  Created by PengFei_Zheng on 17/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <list>
#define maxn 1010
using namespace std;

int parent[maxn];
int n, k, i;
int currNum;
map<string, int> baseMap;

char marray[maxn][4];
char resultArr[maxn][4];
int callTime[maxn];
int singleCallTime[maxn];
int fatherArr[maxn];
int visit[maxn];

struct Node {
    char name[4];
    int size;
} nodes[maxn];

//并查集寻找父亲节点
int findRoot(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

//并查集合并节点
void unionSet(int a, int b) {
    
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;
    if (a > b) {
        parent[a] = b;
    } else {
        parent[b] = a;
    }
}

//初始化基本数据，这在以后会用到
void initData() {
    baseMap.clear();
    memset(callTime, 0, sizeof(callTime));
    memset(visit, 0, sizeof(visit));
    memset(singleCallTime, 0, sizeof(singleCallTime));
    memset(fatherArr, 0, sizeof(fatherArr));
    for (i = 1; i < maxn; i++) {
        parent[i] = i;
    }
}

//将字符串转为数字，否则后面不太好处理
int getCurrentNum(char c[]) {
    int num = 0;
    map<string, int>::iterator it = baseMap.find(c);
    if (it == baseMap.end()) {
        currNum++;
        num = currNum;
        baseMap.insert(make_pair(c, num));
    } else {
        num = it->second;
    }
    return num;
}

//记录每个人打电话的时间
void constructData(char a[], char b[], int anum, int bnum, int d) {
    if (singleCallTime[anum] == 0) {
        singleCallTime[anum] = d;
    } else {
        singleCallTime[anum] += d;
    }
    strcpy(marray[anum], a);
    strcpy(marray[bnum], b);
    callTime[anum] += d;
    callTime[bnum] += d;
}

bool cmp(Node node1, Node node2) {
    return strcmp(node1.name, node2.name) < 0;
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        initData();
        currNum = 0;
        char a[4];
        char b[4];
        int d;
        for (i = 0; i < n; i++) {
            scanf("%s%s%d", a, b, &d);
            int anum = getCurrentNum(a);
            int bnum = getCurrentNum(b);
            constructData(a, b, anum, bnum, d);
            unionSet(anum, bnum);
        }
        
        int tmpk = 1;
        for (i = 1; i < currNum + 1; i++) {
            parent[i] = findRoot(i);
            if (parent[i] == i) {
                fatherArr[tmpk] = i;
                tmpk++;
            }
        }
        int num = 0;
        for (i = 1; i < tmpk; i++) {
            int size = 0;
            int allTime = 0;
            int maxTime = -1;
            int maxMem = 0;
            for (int j = 1; j < currNum + 1; j++) {
                if (fatherArr[i] != 0 && visit[j] == 0) {
                    if (parent[j] == fatherArr[i]) {
                        size++;
                        allTime += singleCallTime[j];
                        if (callTime[j] > maxTime) {
                            maxTime = callTime[j];
                            maxMem = j;
                        }
                        visit[j] = 1;
                    }
                }
            }
            if (size < 3) {
                continue;
            }
            if (allTime <= k) {
                continue;
            }
            strcpy(nodes[num].name, marray[maxMem]);
            nodes[num].size = size;
            num++;
        }
        sort(nodes, nodes + num, cmp);
        printf("%d\n", num);
        for (i = 0; i < num; i++) {
            printf("%s %d\n", nodes[i].name, nodes[i].size);
        }
        
    }
    return 0;
}
