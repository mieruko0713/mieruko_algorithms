//
//  1074.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int st,n,k;

struct Node {
    int address,data,next,order;
}node[maxn];

bool cmp(Node a, Node b) {
    return a.order<b.order;
}

int main() {
    scanf("%d%d%d",&st,&n,&k);
    int i,j,address;
    for(i=0;i<maxn;i++) {
        node[i].order = maxn;
    }

    for(i=0;i<n;i++) {
        scanf("%d",&address);
        node[address].address = address;
        scanf("%d %d",&node[address].data,&node[address].next);
//        printf("%d\n",node[address].data);
    }
    int p = st,count=0;
    while(p!=-1) {
        count++;
        node[p].order = count;
        p = node[p].next;
    }
    
    sort(node,node+maxn,cmp);
//    printf("node[0]:%d\n",node[0].address);
    for(i=0;i<n/k;i++) {
        for(j=(i+1)*k-1;j>i*k;j--) {
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
        }
        printf("%05d %d ",node[j].address,node[j].data);
        if(i<n/k-1) {
            printf("%05d\n",node[(i+2)*k-1].address);
        } else if(i==n/k-1) {
            if(n%k==0) {
                printf("-1\n");
            } else {
                printf("%05d\n",node[n/k*k].address);
            for(int i=n/k*k;i<n;i++) {
                printf("%05d %d ",node[i].address,node[i].data);
                if(i<n-1) {
                    printf("%05d\n",node[i+1].address);
                } else {
                    printf("-1\n");
                }
            }
            }
        }
    }
    return 0;
}
