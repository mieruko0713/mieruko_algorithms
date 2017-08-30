//
//  1118.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int father[maxn];
int isRoot[maxn] = {0};
int pic[maxn] = {0};
int hashes[maxn] = {0};
int n;

void init(int n) {
    int i;
    for(i=1;i<=n;i++) {
        father[i] = i;
    }
}

int findFather(int x) {
    int a = x;
    while(x!=father[x]) {
        x = father[x];
    }
    while(a!=father[a]) {
        int z = a;
        a = father[z];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB) {
        father[faA] = faB;
    }
}


int main() {
    scanf("%d",&n);
    int i,k,b,num=0;
//    init(n);
    for(int i=1;i<maxn;i++) {
        father[i] = i;
    }
    for(i=1;i<=n;i++) {
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%d",&b);
            if(!hashes[b]) {
                num++;
                hashes[b] = 1;
            }
            if(pic[i]==0) {
                pic[i] = b;
            }
//            Union(i,findFather(pic[b]));
            Union(b,findFather(pic[i]));
        }
    }
    for(int i=1;i<=num;i++) {
        if(hashes[i]) {
          isRoot[findFather(i)]++;
        }
    }
    int ans = 0;
    for(int i=1;i<=num;i++) {
        if(hashes[i]&&isRoot[i]) {
            ans++;
        }
    }
    printf("%d %d\n",ans,num);
    int q,q1,q2;
    scanf("%d",&q);
    for(i=0;i<q;i++) {
        scanf("%d%d",&q1,&q2);
        if(findFather(q1)==findFather(q2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
