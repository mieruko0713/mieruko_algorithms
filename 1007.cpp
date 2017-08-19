//
//  1007.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/19.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>

int k;
const int maxn = 10010;

int main() {
    scanf("%d",&k);
    bool flag = true;
    int i,num[maxn],st,left=0,right=0,dp[maxn],maxnum;
    for(i=0;i<k;i++) {
        scanf("%d",&num[i]);
        if(num[i]>=0) {
            flag = false;
        }
        dp[i] = num[i];
    }
    st = 0;
    maxnum = dp[0];
    if(flag) {
        printf("0 %d %d",num[0],num[k-1]);
        return 0;
    }
    for(i=1;i<k;i++) {
        if(dp[i-1]<0) {
            st = i;
            continue;
        }
        dp[i] = num[i] + dp[i-1];
        if(dp[i]>maxnum) {
            maxnum = dp[i];
            left = st;
            right = i;
        }
    }
    printf("%d %d %d",maxnum,num[left],num[right]);
    return 0;
}
