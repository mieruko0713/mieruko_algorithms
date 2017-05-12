//
//  1001.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/12.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;

int main() {
    int a,b,c,len=0,i;
    int num[10];
    scanf("%d %d",&a,&b);
    c = a + b;
    if(c<0){
        printf("-");
        c=-c;
    }
    if(c==0) {
        printf("0");
        return 0;
    }
    while(c) {
        num[len++] = c%10;
        c=c/10;
    }
    for(i=len-1;i>=0;i--) {
         printf("%d",num[i]);
        if(i%3==0&&i>0) {
            printf(",");
        }
       
    }
    return 0;
}
