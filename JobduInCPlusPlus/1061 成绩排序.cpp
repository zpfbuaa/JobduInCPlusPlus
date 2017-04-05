//
//  1061 成绩排序.cpp
//  oj
//
//  Created by PengFei_Zheng on 03/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string.h>
#include <cstring>

using namespace std;

int n;
struct Stu{
    string name;
    int age;
    int grade;
    bool operator < (const Stu &b) const{
        if(grade!=b.grade) return grade<b.grade;
        int temp = strcmp(name.c_str(), b.name.c_str());
        if(temp!=0)return temp<0;
        else return age<b.age;
    }
}stu[1001];

bool cmp(Stu a, Stu b){
    if(a.grade!=b.grade) return a.grade<b.grade;
    int result = strcmp(a.name.c_str(),b.name.c_str());
    if(result) return result<0;
    else return a.age<b.age;
}
int main(){
    while(cin>>n){
        for(int i = 0 ; i < n ; i++){
            cin>>stu[i].name>>stu[i].age>>stu[i].grade;
        }
//        sort(stu,stu+n,cmp);
        sort(stu,stu+n);
        for(int i =0 ; i < n ; i ++){
            cout<<stu[i].name<<" "<<stu[i].age<<" "<<stu[i].grade<<endl;
        }
    }
    return 0;
    
}
