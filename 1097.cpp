//
//  1097.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn = 100010;
int st,n;
int hashes[10010] = {false};

struct Node {
    int address,data,next,order;
}node[maxn*2];

bool cmp(Node a, Node b) {
    return a.order < b.order;
}


int main(){
    scanf("%d%d",&st,&n);
    int i,address;
    for(i=0;i<maxn;i++) {
        node[i].order = maxn;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&address);
        
        node[address].address = address;
        scanf("%d %d",&node[address].data,&node[address].next);
    }
    int now = st,order=0;
    while(now!=-1) {
        node[now].order=order++;
        now = node[now].next;
    }
    sort(node,node+maxn,cmp);
    printf("%05d %d",node[0].address,node[0].data);
    int count=0;
    hashes[abs(node[0].data)] = true;
    for(i=1;i<n;i++) {
        int data = abs(node[i].data);
        if(hashes[data]) {
            node[maxn+count] = node[i];
            count++;
            if(i==n-1) {
                printf(" -1\n");
            }
        } else {
            printf(" %05d\n",node[i].address);
            hashes[data] = true;
            if(i!=n-1){
               printf("%05d %d",node[i].address,node[i].data);
            } else {
                printf("%05d %d -1\n",node[i].address,node[i].data);
            }
        }
    }
    for(i=maxn;i<count+maxn;i++) {
        if(i<maxn+count-1){
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        } else {
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
        
    }
    return 0;
}
