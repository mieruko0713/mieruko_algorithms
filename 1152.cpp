//
//  1152.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm> 
using namespace std;

const int maxn = 100010;
struct node {
    int ad,value,next;
    bool flag;
}Nodes[maxn];

bool cmp(node a, node b) {
    if(a.flag==false || b.flag==false) {
        return a.flag>b.flag;
    } else {
        return a.value<b.value;
    }
}

int main() {
    int i,n,start,ad,value,next,num=0;
    scanf("%d%d",&n,&start);
    for(i=0;i<n;i++) {
        scanf("%d%d%d",&ad,&value,&next);
        Nodes[ad].value = value;
        Nodes[ad].next = next;
        Nodes[ad].ad = ad;
    }
//    if(num==0) {
//        printf("0 -1");
//        return 0;
//    }
//    printf("Node.value默认值:%d",Nodes[100].value);
    for(i=start;i!=-1;i=Nodes[i].next) {
        Nodes[i].flag = true;
        num++;
    }
    if(num==0) {
        printf("0 -1");
        return 0;
    }
    sort(Nodes,Nodes+maxn,cmp);
    printf("%d %05d\n",num,Nodes[0].ad);
    for(i=0;i<num;i++) {
        if(i!=num-1){
            printf("%05d %d %05d\n",Nodes[i].ad,Nodes[i].value,Nodes[i+1].ad);
        } else {
            printf("%05d %d -1\n",Nodes[i].ad,Nodes[i].value);
        }
    }
    return 0;
}