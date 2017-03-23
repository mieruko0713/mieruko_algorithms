//
//  1097.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 100005;
const int table = 1000010;
struct Node {
    int address, data, next;
    int order;
}node[maxn];
bool isExist[table] = {false};
bool cmp(Node a, Node b) {
    return a.order<b.order;
}
int main() {
    memset(isExist, false, sizeof(isExist));
    int i;
    for(i=0;i<maxn;i++) {
        node[i].order = 2*maxn;
    }
    int n, begin, address;
    scanf("%d %d",&begin,&n);
    for(i=0;i<n;i++) {
        scanf("%d",&address);
        scanf("%d %d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int countValid=0,countRemoved=0,p=begin;
    while(p!=-1) {
        int data = node[p].data;
        if(!isExist[abs(data)]) {
            isExist[abs(data)] = true;
            node[p].order = countValid++;
        } else {
            node[p].order = maxn + countRemoved++;
        }
        p = node[p].next;
    }
    sort(node,node+maxn,cmp);
    int count=countValid + countRemoved;
    for(i=0;i<count;i++) {
        if(i!=countValid-1&&i!=count-1) {
            printf("%05d %d %05d\n",node[i].address, node[i].data, node[i+1].address);
        } else {
            printf("%05d %d -1\n",node[i].address, node[i].data);

        }
    }
    return 0;
}
