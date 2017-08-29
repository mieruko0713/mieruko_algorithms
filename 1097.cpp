//
//  1097.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn = 100010;
int n,st;

struct Node {
    int data,address,next,order;
}node[maxn];

int hashes[10010] = {0};

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    scanf("%d%d",&st,&n);
    int i,address;
    for(i=0;i<n;i++) {
        scanf("%d",&address);
        node[address].address =address;
        scanf("%d%d",&node[address].data,&node[address].next);
    }
    for(i=0;i<maxn;i++) {
        node[i].order=2*maxn;
    }
    int now =st,order=0,count1=0,count=0;
    while(now!=-1) {
        node[now].order = order++;
        int data = abs(node[now].data);
        if(hashes[data]==0) {
            hashes[data] = 1;
            count1++;
        } else {
            node[now].order += maxn;
        }
        now = node[now].next;
        count++;
    }
    sort(node,node+maxn,cmp);
    for(i=0;i<count;i++) {
        if(i==count1-1 || i==count-1) {
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }else {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
    }
    return 0;
}
