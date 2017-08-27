//
//  1065.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
typedef long long ll;
ll a,b,c;

int main(){
    int n,i;
    scanf("%d",&n);
    ll sum;
    for(i=0;i<n;i++) {
        scanf("%lld%lld%lld",&a,&b,&c);
        sum = a+b;
        if(a>0&&b>0&&sum<0) {
            printf("Case #%d: true\n",i+1);
        } else if(a<0&&b<0&&sum>=0) {
            printf("Case #%d: false\n",i+1);
        } else {
            if(sum>c) {
                printf("Case #%d: true\n",i+1);
            } else {
                printf("Case #%d: false\n",i+1);
            }
        }
    }
    return 0;
}
