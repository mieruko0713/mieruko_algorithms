//
//  1031.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
char s[90];

int main() {
    scanf("%s",s);
    int i,j,len=int(strlen(s)),a,b;
    a = min((len-1)/2,(len+2)/3);
    b = len+2-2*a;
    for(i=0;i<a-1;i++) {
        printf("%c",s[i]);
        for(j=0;j<b-2;j++) {
            printf(" ");
        }
        printf("%c",s[len-i-1]);
        printf("\n");
    }
    for(j=0;j<b;j++) {
        printf("%c",s[i]);
        i++;
    }
    
//    for(j=b/2;j<b;j++) {
//        printf("%c",s[len-i-1]);
//        i++;
//    }
    return 0;
}
