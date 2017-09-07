//
//  1121.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/7.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n,k,G[maxn],hashes[maxn],id[maxn],ans[50010];

int main() {
    scanf("%d",&n);
    int i,u,v;
    for(i=0;i<n;i++) {
        scanf("%d %d",&u,&v);
        G[u] = v;
        G[v] = u;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d",&id[i]);
        hashes[id[i]]=1;
    }
    int num=0;
    for(i=0;i<k;i++) {
        if(hashes[G[id[i]]]==0) {
            ans[num++]=id[i];
        }
    }
    printf("%d\n",num);
    sort(ans,ans+num);
    for(i=0;i<num;i++) {
        printf("%05d",ans[i]);
        if(i!=num-1) {
            printf(" ");
        }
    }
    return 0;
}
