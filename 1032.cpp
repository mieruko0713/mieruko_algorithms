//
//  1032.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
using namespace std;

const int maxn = 100000;
int st1,st2,n;
int hashes[maxn] = {0};

struct node {
    int next;
    char data;
}nodes[maxn];



int main() {
    scanf("%d%d%d",&st1,&st2,&n);
    int i,ad;
    for(i=0;i<n;i++) {
        scanf("%d",&ad);
        getchar();
        scanf("%c %d",&nodes[ad].data,&nodes[ad].next);
//        printf("%d %c %d\n",ad,nodes[ad].data,nodes[ad].next);
    }
    int now = st1;
    while(now!=-1) {
        hashes[now] = 1;
        now = nodes[now].next;
    }
    now = st2;
    while(now!=-1) {
        if(hashes[now]) {
            printf("%05d",now);
            break;
        }
        now = nodes[now].next;
    }
    if(now==-1) {
        printf("-1");
    }
    return 0;
}
