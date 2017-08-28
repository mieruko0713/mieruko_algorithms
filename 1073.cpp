//
//  1073.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
using namespace std;

const int maxn = 10010;
char str[maxn];

int main() {
    scanf("%s",str);
    int len = int(strlen(str));
    int i,pos=0,exp=0;
    if(str[0]=='-') {
        printf("-");
    }
        while(str[pos]!='E') {
            pos++;
        }
    for(i=pos+2;i<len;i++) {
        exp = exp*10 + (str[i]-'0');
    }
    if(exp==0) {
        for(i=1;i<len;i++) {
            printf("%c",str[i]);
        }
    }
    if(str[pos+1]=='-') {
        printf("0.");
        for(i=0;i<exp-1;i++) {
            printf("0");
        }
        for(i=1;i<pos;i++) {
            if(str[i]!='.') {
                printf("%c",str[i]);
            }
        }
    } else {
        for(i=1;i<pos;i++) {
            if(str[i]=='.') continue;
            printf("%c",str[i]);
            if(i==exp+2&&exp+3<pos) {
                printf(".");
            }
        }
        for(i=0;i<exp+2-(pos-1);i++) {
            printf("0");
        }
    }
    return 0;
}
