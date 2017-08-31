//
//  1074.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int st,n,k;

struct Node{
    int address,data,next,order;
}node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    scanf("%d %d %d",&st,&n,&k);
    int i,address;
    for(i=0;i<maxn;i++) {
        node[i].order = maxn;
    }
    for(i=0;i<n;i++){
        scanf("%d",&address);
        node[address].address = address;
        scanf("%d %d",&node[address].data,&node[address].next);
    }
    int now = st,order=0;
    while(now!=-1) {
        node[now].order = order++;
        now = node[now].next;
    }
    n = order;
    sort(node,node+maxn,cmp);
    int j;
    for(i=0;i<n/k;i++) {
        for(j=(i+1)*k-1;j>i*k;j--) {
                printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        if(i!=n/k-1) {
           printf("%05d %d %05d\n",node[j].address,node[j].data,node[(i+2)*k-1].address);
        } else {
           printf("%05d %d ",node[j].address,node[j].data);
        }
    }
    if(n%k==0) {
        printf("-1\n");
    } else {
        printf("%05d\n",node[(n/k)*k].address);
        for(j=(n/k)*k;j<n-1;j++) {
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j].next);
        }
        printf("%05d %d -1\n",node[j].address,node[j].data);
    }
    return 0;
}
