//
//  1081.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
int n;
const int maxn = 110;

long int gcd(long int a, long int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main() {
    long int moth[maxn],chil[maxn],i;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%ld/%ld",&chil[i],&moth[i]);
    }
    long int gc,lc;
    for(i=0;i<n-1;i++) {
        gc = gcd(moth[i],moth[i+1]);
        lc = moth[i]*moth[i+1]/gc;
    }
    long int sum = 0;
    for(i=0;i<n;i++) {
        if(chil[i]!=0) {
            sum += (lc/moth[i])*chil[i];
        }
    }
//    printf("%ld %ld",sum,lc);
    long int gc2 = gcd(sum,lc);
    sum = sum/gc2;
    lc = lc / gc2;
    long int inte = sum/lc;
    long int out = sum % lc;
    if(inte!=0) {
        printf("%ld",inte);
    }
    if(inte!=0) {
        if(out!=0) {
            printf(" %ld/%ld",out,lc);
        }
    } else {
        if(out==0) {
            printf("%ld",out);
        } else {
            printf("%ld/%ld",out,lc);
        }
    }
    
    return 0;
}
