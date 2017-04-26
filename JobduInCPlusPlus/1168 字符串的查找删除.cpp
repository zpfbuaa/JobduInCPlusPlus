//
//  1168 字符串的查找删除.cpp
//  oj
//
//  Created by PengFei_Zheng on 03/04/2017.
//  Copyright © 2017 PengFei_Zheng. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>


char c[1001];
int match_len = 0;
char ch;

using namespace std;

int main(){
    
    scanf("%s",c);
    int len = (int)strlen(c);//the length of pattern
    ch=getchar();//remove the space or return after input c
    while((ch=getchar())!=EOF){//get each char
        if(tolower(ch)==tolower(c[match_len])) {//find same character
            match_len++;//move index to next position
            if(match_len>=len) match_len=0;// reinitation ,if ch==c[len-1] then next i will be assigned len
        }
        else{
            if(match_len==0){//now position is not satisfy
                if(ch!=' ') cout<<ch;//cout now char
            }
            else{//the array c is just right save the cahracter which is not cout to the screen
                for(int k=0;k<match_len;k++){//now i keeps to the position max_match_length
                    cout<<(c[k]);
                }
                match_len=0;//reinitation i to 0
                if(ch != ' ')  putchar(ch);//cout right now character
            }
        }
    }
    
}
