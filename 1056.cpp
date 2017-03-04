//
//  1056.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/3.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1010;

struct mouse {
    int weight;
    int rank;
}mouse[maxn];

int main() {
    int i,j,np, ng, order;
    scanf("%d%d",&np,&ng);
    for(i=0;i<np;i++) {
        scanf("%d",&mouse[i].weight);
    }
    queue<int> q;
    for(i=0;i<np;i++) {
        scanf("%d",&order);
        q.push(order);
    }
    int temp=np,group;
    while(q.size()!=1) {
        int k = q.front();
        if(temp%ng==0) {
            group = temp/ng;
        } else{
            group = temp/ng + 1;
        }
        for(i=0;i<group;i++) {
            int k = q.front();
            for(j=0;j<ng;j++) {
                if(i*ng+j>=temp) {
                    break;
                }
                int front = q.front();
                if(mouse[front].weight>mouse[k].weight) {
                    k = front;
                }
                mouse[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].rank = 1;
    for(i=0;i<np;i++) {
        printf("%d",mouse[i].rank);
        if(i<np-1) {
            printf(" ");
        }
    }
    return 0;
}