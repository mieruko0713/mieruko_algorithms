//
//  1007.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;

const int maxn = 10010;
int num[maxn],start[maxn],max,d[maxn];

int main() {
    int k,i;
    bool flag = false;
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d",&num[i]);
        if(num[i]>=0) {
            flag = true;
        }
    }
    if(!flag) {
        printf("0 %d %d\n",num[0],num[k-1]);
        return 0;
    }
    d[0] = num[0];
    max = d[0];
    for(i=1;i<k;i++) {
        if(d[i-1]+num[i]>num[i]) {
            d[i] = d[i-1] + num[i];
            start[i] = start[i-1];
        } else {
            d[i] = num[i];
            start[i] = i;
        }
        if(d[i]>max) {
            max = d[i];
        }
    }
    printf("%d", max);
    for(i=0;i<k;i++) {
        if(d[i]==max) {
            printf(" %d %d\n",start[i],i);
            break;
        }
    }
    return 0;
}
