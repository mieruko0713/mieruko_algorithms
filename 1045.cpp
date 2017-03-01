//
//  1045.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 210;
const int maxall = 10010;
int Hash[maxn];
int A[maxall], dp[maxall];

int main() {
    int i,j,n,m,x;
    scanf("%d%d",&n,&m);
    fill(Hash,Hash+maxn,-1);
//    printf("A[n]: %d\n",A[100]);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        Hash[x] = i;
    }
    int L, num=0;
    scanf("%d",&L);
    for(i=0;i<L;i++) {
        scanf("%d",&x);
        if(Hash[x]>=0) {
            A[num++] = Hash[x];
//            printf("x: %d hash[x]: %d\n",x,Hash[x]);
        }
    }
    int ans = -1;
    for(i=0;i<num;i++) {
        dp[i] = 1;
        for(j=0;j<i;j++) {
            if(A[j]<=A[i]&&dp[j]+1>dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
//        printf("ans: %d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}

