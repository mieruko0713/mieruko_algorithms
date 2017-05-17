//
//  1009.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/15.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1100;

float ans[2001];

struct poly {
    int ex;
    float co;
}polis[maxn];


int main() {
    int k1, k2, i,j,num=0;
    poly p;
    scanf("%d",&k1);
    for(i=0;i<k1;i++) {
        scanf("%d %f",&p.ex,&p.co);
        polis[i] = p;
    }
    scanf("%d",&k2);
    for(i=0;i<k2;i++) {
        scanf("%d %f",&p.ex,&p.co);
        for(j=0;j<k1;j++) {
            ans[polis[j].ex+p.ex] += polis[j].co*p.co;
        }
    }
    for(i=2000;i>=0;i--) {
        if(ans[i]!=0.0) {
            num++;
        }
    }
    printf("%d",num);
    for(i=2000;i>=0;i--) {
        if(ans[i]!=0.0) {
            printf(" %d %.1f",i,ans[i]);
        }
    }
    return 0;
}
