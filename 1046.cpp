//
//  1046.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
const int maxn = 100010;
int n,dis[maxn];

int main() {
    scanf("%d",&n);
    int i,m,query1,query2,all=0;
    dis[1] = 0;
    for(i=2;i<=n+1;i++) {
        scanf("%d",&dis[i]);
        dis[i] = dis[i] + all;
        all = dis[i];
    }
    scanf("%d",&m);
    int sum;
    for(i=0;i<m;i++) {
        scanf("%d%d",&query1,&query2);
        if(query1==query2) {
            printf("0\n");
            continue;
        }
        if(query1>query2) {
            int t = query1;
            query1 = query2;
            query2 = t;
        }
        sum = dis[query2] - dis[query1];
        if(sum>all-sum) {
            sum = all-sum;
        }
         printf("%d\n",sum);
    }
    return 0;
}
