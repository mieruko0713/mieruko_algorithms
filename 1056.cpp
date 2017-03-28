//
//  1056.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1010;

struct mouse {
    int weight;
    int r;
}mouse[maxn];

int main() {
    int np, ng, order;
    scanf("%d%d",&np,&ng);
    int i;
    for(i=0;i<np;i++) {
        scanf("%d",&mouse[i].weight);
    }
    queue<int> q;
    for(i=0;i<np;i++) {
        scanf("%d",&order);
        q.push(order);
    }
    int temp=np, group;
    while(q.size()!=1) {
        if(temp%ng==0) {
            group=temp/ng;
        } else {
            group = temp/ng + 1;
        }
        for(i=0;i<group;i++) {
            int j,k = q.front();
            for(j=0;j<ng;j++) {
                if(i*ng+j>=temp) break;
                int front = q.front();
                if(mouse[front].weight > mouse[k].weight) {
                    k = front;
                }
                mouse[front].r = group+1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].r = 1;
    for(i=0;i<np;i++) {
        printf("%d",mouse[i].r);
        if(i<np-1) {
            printf(" ");
        }
    }
    return 0;
}
