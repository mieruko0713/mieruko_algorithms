//
//  1096.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;

int main() {
    scanf("%lld",&n);
    ll sqr = (ll)sqrt(1.0*n);
    ll ansLen = 0,ansI=0;
    for(ll i=2;i<=sqr;i++){
        ll temp=1;
        ll j=i;
        while(1){
            temp *= j;
            if(n%temp!=0) break;
            if(j-i+1>ansLen) {
                ansI = i;
                ansLen = j-i+1;
            }
            j++;
        }
    }
    if(ansLen == 0) {
        printf("1\n%lld",n);
    } else {
        printf("%lld\n",ansLen);
        for(ll i=0;i<ansLen;i++) {
            printf("%lld",ansI+i);
            if(i<ansLen-1) {
                printf("*");
            }
        }
    }
    return 0;
}
