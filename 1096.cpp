//
//  1096.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long LL;
using namespace std;

int main() {
    LL n;
    scanf("%lld",&n);
    LL sqr = (LL)sqrt(1.0*n), ansI=0, ansLen=0;
    for(LL i=2;i<=sqr;i++) {
        LL temp = 1, j=i;
        while(1) {
            temp *= j;
            if(n%temp!=0) break;
            if(j-i+1>ansLen) {
                ansI = i;
                ansLen = j-i+1;
            }
            j++;
        }
    }
    if(ansLen==0) {
        printf("1\n%lld",n);
    } else {
        printf("%lld\n",ansLen);
        for(LL i=0;i<ansLen;i++) {
            printf("%lld",ansI+i);
            if(i<ansLen-1) {
                printf("*");
            }
        }
    }
    return 0;
}
